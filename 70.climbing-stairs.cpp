#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 本题动态规划思考方式:
// -『不选/选』
// -『枚举选哪个』-> 本题!

// dfs(i): 从 0 爬到 i 有多少种方法
// 分类:
// - 最后一步爬 1 个台阶: 子问题 -> 从 0 ~ i-1 有多少种方法
// - 最后一步爬 2 个台阶: 子问题 -> 从 0 ~ i-2 有多少种方法
// 加法原理: dfs(i) = dfs(i - 1) + dfs(i - 2)
// 递归边界: dfs(0) = 1, dfs(1) = 1

// @leet start
class Solution {
    enum Method {
        DFS,       // 普通递归 (超时)
        DFS_MEMO,  // 递归 + 记忆化搜索
        DP_F,      // 递推 (普通 f 数组)
        DP_NEW_F,  // 递推 (只用三个状态)
    };

public:
    int climbStairs(int n) {
        Method method{DP_NEW_F};
        switch (method) {
            case DFS: {
                return SolveDfs(n);
            }
            case DFS_MEMO: {
                return SolveDfsMemo(n);
            }
            case DP_F: {
                return SolveDpF(n);
            }
            case DP_NEW_F: {
                return SolveDpNewF(n);
            }
        }
    }

    int SolveDpNewF(int n) {
        // 三个状态写法 (空间复杂度 O(1))
        // f0: 上上个
        // f1: 上个
        int f0 = 1, f1 = 1;
        int new_f;
        for (int i = 2; i <= n; ++i) {
            new_f = f0 + f1;
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }

    int SolveDpF(int n) {
        // 常规 f 数组写法 (空间复杂度 O(n))
        // f(i) = f(i-1) + f(i-2)
        vector<int> f(n + 1);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }

    // 递归 + 记忆化搜索
    int SolveDfsMemo(int n) {
        vector<int> memo(n + 1, -1);  // HACK: 记忆数组: 0 ~ n 一共 n + 1 个
        auto dfs = [&](auto&& self, int i) {
            if (i == 0 || i == 1) {  // NOTE: 递归边界!! 0 ~ 0 的方法也是 1 种
                return 1;
            }
            auto& res{memo[i]};
            if (res != -1) {  // 如果存在 dfs(i) 的记忆, 则直接返回结果
                return res;
            }
            res = self(self, i - 1) + self(self, i - 2);  // 不存在记忆则保存
            return res;
        };
        return dfs(dfs, n);
    }

    // 递归 (超时)
    int SolveDfs(int n) {
        auto dfs = [&](auto&& self, int i) {
            if (i == 0 || i == 1) {  // NOTE: 递归边界!! 0 ~ 0 的方法也是 1 种
                return 1;
            }
            return self(self, i - 1) + self(self, i - 2);
        };
        return dfs(dfs, n);
    }
};
// @leet end

int main() { return 0; }
