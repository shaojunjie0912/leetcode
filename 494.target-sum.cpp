#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 设正号的元素和为 p
// 则负号的元素和为 q
// p + q = s
// p - q = target
// p = (s + target) / 2
// q = (s - target) / 2
// 如果 target >= 0 则选 q 作为背包容量更好 (计算量少)
// 如果 target < 0 则选 p 作为背包容量更好 (计算量少)
// 因此选 new_target = (s - |target|) / 2
// 问题转化: 从 nums 中选一些数字, 使得他们的和恰好等于 new_target

// dfs(i, c) = dfs(i - 1, c) + dfs(i - 1, c - nums[i])

// @leet start
class Solution {
    enum Method {
        DFS_MEMO,        // 递归 + 记忆化搜索
        DP_2D,           // 递推 (普通二维 f 数组)
        DP_2ROWS_MOD,    // 递推 (普通二维 f 数组的两行)
        DP_1D_BACKWARD,  // 递推 (一维数组)
    };

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        Method method{DP_1D_BACKWARD};

        switch (method) {
            case DFS_MEMO:
                return SolveDFSMemo(nums, target);
            case DP_2D:
                return Solve2D(nums, target);
            case DP_2ROWS_MOD:
                return Solve2RowMod(nums, target);
            case DP_1D_BACKWARD:
                return Solve1DBackward(nums, target);
            default:
                throw std::invalid_argument("Unsupported method");
        }
    }

    // 递推 (空间优化版 2)
    // 去除第一维度, 只用一维数组 (从后往前计算)
    // f[c] = f[c] + f[c - nums[i]]
    int Solve1DBackward(vector<int>& nums, int target) {
        int s = reduce(nums.begin(), nums.end()) - abs(target);
        if (s < 0 || s % 2 == 1) {
            return 0;
        }
        int new_target = s / 2;  // 背包容量
        int n = nums.size();
        vector<int> f(new_target + 1);  // 只用一个数组存储 0 ~ new_target
        f[0] = 1;                       // 初始值
        // 同样的双重循环, 但是只计算 c>= x 的情况
        for (auto& x : nums) {
            for (int c = new_target; c >= x; --c) {
                f[c] += f[c - x];
            }
        }
        return f[new_target];
    }

    // 递推 (空间优化版 1)
    // 计算过程只需要两个状态(即二维数组的 f0 和 f1)
    // 例如通过 f0 计算得出了 f1
    // 再通过 f1 计算得出的 f2 直接放入 f0 中
    // 通过 f2 计算得出的 f3 放入 f1 中
    // HACK: 取模即可
    // f[(i + 1) % 2][c] = f[i % 2][c] + f[i % 2][c - nums[i]]
    int Solve2RowMod(vector<int>& nums, int target) {
        int s = reduce(nums.begin(), nums.end()) - abs(target);
        if (s < 0 || s % 2 == 1) {
            return 0;
        }
        // NOTE: 计算背包容量 (注意: new_target >= 0)
        int new_target = s / 2;
        int n = nums.size();
        // dfs -> f 数组, 二维 (第一维只有 2 个)
        // 用 i+1 避免下标访问 -1 越界, 所以 n 多了一个
        // NOTE: 默认初始为 0, 跟记忆数组 memo 不一样!!!
        vector f(2, vector<int>(new_target + 1));
        // 初始值
        f[0][0] = 1;
        // 递归 -> 循环
        for (int i = 0; i < n; ++i) {  // NOTE: 这里还是 n 不是 2, 毕竟要循环的嘛!
            // NOTE: <= new_target
            for (int c = 0; c <= new_target; ++c) {
                if (nums[i] > c) {  // 只能不选
                    f[(i + 1) % 2][c] = f[i % 2][c];
                } else {
                    // 不选 + 选
                    f[(i + 1) % 2][c] = f[i % 2][c] + f[i % 2][c - nums[i]];
                }
            }
        }
        return f[n % 2][new_target];  // NOTE: 此时 f 数组最后一个是 n
    }

    // 递推 (普通 f 数组写法)
    // f[i][c] = f[i - 1][c] + f[i - 1][c - nums[i]]
    // f[i + 1][c] = f[i][c] + f[i][c - nums[i]]
    int Solve2D(vector<int>& nums, int target) {
        int s = reduce(nums.begin(), nums.end()) - abs(target);
        if (s < 0 || s % 2 == 1) {
            return 0;
        }
        // NOTE: 计算背包容量 (注意: new_target >= 0)
        int new_target = s / 2;
        int n = nums.size();
        // dfs -> f 数组, 二维, 第二维包含了 0 ~ new_target
        // 用 i+1 避免下标访问 -1 越界, 所以 n 多了一个
        // NOTE: 默认初始为 0, 跟记忆数组 memo 不一样!!!
        vector f(n + 1, vector<int>(new_target + 1));
        // 初始值
        f[0][0] = 1;
        // 递归 -> 循环
        for (int i = 0; i < n; ++i) {
            // NOTE: <= new_target
            for (int c = 0; c <= new_target; ++c) {
                if (nums[i] > c) {  // 只能不选
                    f[i + 1][c] = f[i][c];
                } else {
                    // 不选 + 选
                    f[i + 1][c] = f[i][c] + f[i][c - nums[i]];
                }
            }
        }
        return f[n][new_target];  // NOTE: 此时 f 数组最后一个是 n
    }

    // 递归 + 记忆化搜索
    // dfs(i, c) = dfs(i - 1, c) + dfs(i - 1, c - nums[i])
    // HACK: 关键是重新计算背包容量
    int SolveDFSMemo(vector<int>& nums, int target) {
        int s = reduce(nums.begin(), nums.end()) - abs(target);
        if (s < 0 || s % 2 == 1) {
            return 0;
        }
        // NOTE: 计算背包容量 (注意: new_target >= 0)
        int new_target = s / 2;
        int n = nums.size();
        // NOTE: 记忆数组, 这里是二维的, 第二维代表 0 ~ new_target
        vector memo(n, vector(new_target + 1, -1));
        auto dfs = [&](auto&& self, int i, int c) -> int {
            if (i < 0) {        // 递归边界
                return c == 0;  // 如果剩余 c 为 0, 则方案有效
            }
            auto& res{memo[i][c]};  // 读取记忆 (引用)
            if (res != -1) {
                return res;
            }
            if (nums[i] > c) {  // 当前元素大于 c, 一定不能选
                res = self(self, i - 1, c);
            } else {  // 不选 + 选
                res = self(self, i - 1, c) + self(self, i - 1, c - nums[i]);
            }
            return res;
        };
        return dfs(dfs, n - 1, new_target);  // HACK: new_target
    }
};
// @leet end

int main() { return 0; }
