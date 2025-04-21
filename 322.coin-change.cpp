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

// 完全背包 (每种物品可以选无限次)

// 总金额: capacity
// w: 某种硬币的面额
// v: 1 个硬币
// NOTE: 本题最小金额是 min 了, 边界条件要搭配正数最大 INT_MAX

// @leet start
class Solution {
    enum Method {
        DFS_MEMO,        // 递归 + 记忆化搜索
        DP_2D,           // 递推 (普通二维 f 数组)
        DP_1D_BACKWARD,  // 递推 (一维数组)
    };

public:
    int coinChange(vector<int>& coins, int amount) {
        Method method{DP_1D_BACKWARD};

        switch (method) {
            case DFS_MEMO: {
                return SolveDFSMemo(coins, amount);
            }
            case DP_2D: {
                return Solve2D(coins, amount);
            }
            case DP_1D_BACKWARD: {
                return Solve1DBackward(coins, amount);
            }
        }
    }

private:
    // 递推 (一维数组)
    // f[c] = min(f[c], f[c - coins[i]] + 1)
    int Solve1DBackward(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> f(amount + 1, INT_MAX / 2);
        f[0] = 0;
        // 同样的双重循环, 但是只计算 c <= amount 的情况
        // TODO: 正序计算是正确的!
        for (auto& x : coins) {
            for (int c = x; c <= amount; ++c) {
                f[c] = min(f[c], f[c - x] + 1);
            }
        }
        int ans = f[amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }

    // 递推 (普通二维 f 数组)
    // f[i][c] = min(f[i - 1][c], f[i][c - coins[i]] + 1)
    // f[i + 1][c] = min(f[i][c], f[i + 1][c - coins[i]] + 1)
    int Solve2D(vector<int>& coins, int amount) {
        int n = coins.size();
        vector f(n + 1, vector<int>(amount + 1, INT_MAX / 2));
        // 初始条件
        f[0][0] = 0;
        for (int i = 0; i < n; ++i) {            // 对应 n 种硬币, 是 < n
            for (int c = 0; c <= amount; ++c) {  // 对应 0 ~ amount 金额
                // HACK: 别忘记判断 coins[i] > c 的情况
                if (coins[i] > c) {  // 一定不能选
                    f[i + 1][c] = f[i][c];
                } else {  // min(不选, 选)
                    f[i + 1][c] = min(f[i][c], f[i + 1][c - coins[i]] + 1);
                }
            }
        }
        int ans = f[n][amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }

    // 递归 + 记忆化搜索
    // dfs(i, c) = min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1)
    int SolveDFSMemo(vector<int>& coins, int amount) {
        int n = coins.size();
        // 记忆数组 (n, amount + 1)
        vector memo(n, vector<int>(amount + 1, -1));
        auto dfs = [&](auto&& self, int i, int c) -> int {
            if (i < 0) {
                // i < 0 此时 c==0 则说明需要 0 硬币
                // 否则返回较大的数表示不可行, 这里除以 2 防止下面 + 1 溢出
                return c == 0 ? 0 : INT_MAX / 2;
            }
            auto& res{memo[i][c]};  // 读取记忆
            if (res != -1) {
                return res;
            }
            if (coins[i] > c) {  // 面额大于剩余总金额, 肯定不能选
                res = self(self, i - 1, c);
            } else {  // HACK: 这里 else 别忘记!!!
                // min(不选, 选)
                // NOTE: 如果选了, 那么剩余金额 - coins[i] 且硬币数 + 1
                res = min(self(self, i - 1, c), self(self, i, c - coins[i]) + 1);
            }
            return res;
        };
        int ans = dfs(dfs, n - 1, amount);
        // NOTE: 判断如果 ans 超出 INT_MAX/2 则表示无法凑成总金额
        return ans < INT_MAX / 2 ? ans : -1;
    }
};
// @leet end

int main() { return 0; }
