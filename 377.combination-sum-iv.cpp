#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 因为顺序不同的序列是「不同组合」, 所以本题其实计算的是「排列」

// 「爬楼梯」
// 每次可以爬 1 / 2 个台阶 : dfs(i) = dfs(i - 1) + dfs(i - 2)

// 本题可类比爬楼梯, 每次可以爬 nums[i] 个台阶, 一共有 target 个
// dfs(i) : 爬 i 个台阶的方案数
// dfs(i) = sum(dfs(i - nums[j])) 注: nums[j] <= i

// NOTE: 跟完全背包的区别:
// 1. 本题是排列, 完全背包是组合
// 2. 本题外层循环枚举体积, 内层循环枚举物品
// 2. 完全背包外层循环枚举物品, 内层循环枚举体积

// @leet start
class Solution {
    enum Method {
        DFS_MEMO,
        DP_F,
    };

public:
    int combinationSum4(vector<int>& nums, int target) {
        Method method{DFS_MEMO};
        switch (method) {
            case DFS_MEMO: {
                return SolveDfsMemo(nums, target);
            }
            case DP_F: {
                return SolveDpF(nums, target);
            }
        }
    }

private:
    // dfs(i) = sum(dfs(i - nums[j])) 注: nums[j] <= i
    int SolveDfsMemo(vector<int>& nums, int target) {
        // NOTE: 这里是 target + 1, 不是 nums.size() + 1
        vector memo(target + 1, -1);
        auto dfs = [&](auto&& self, int i) {
            // 去除 step > i 的情况 (也可以在 for 循环中加 step<= i 判断)
            // if (i < 0) {
            //     return 0;
            // }
            if (i == 0) {  // 边界条件: 爬 0 个台阶方案数为 1
                return 1;
            }
            auto& res = memo[i];
            if (res != -1) {
                return res;
            }
            res = 0;  // NOTE: 这里赋值 0 再累加, 不然 -1 就错了
            for (auto step : nums) {
                if (step <= i) {
                    res += self(self, i - step);
                }
            }
            return res;
        };
        return dfs(dfs, target);
    }

    // f[i]  = sum(f[i - nums[j]]) 注: nums[j] <= i
    int SolveDpF(vector<int>& nums, int target) {
        // f 数组
        // 使用 unsigned 可以让溢出不报错
        // 对于溢出的数据，不会影响答案的正确性 (题目保证)
        vector<uint32_t> f(target + 1, 0);
        // 初始值
        f[0] = 1;
        for (int i = 1; i < target + 1; ++i) {
            for (auto step : nums) {
                if (step <= i) {
                    f[i] += f[i - step];
                }
            }
        }
        return f[target];
    }
};
// @leet end

int main() { return 0; }
