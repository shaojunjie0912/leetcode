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

// 动态规划: 最长公共子序列

// @leet start
class Solution {
    enum Method {
        DFS_MEMO,
        // DP_2D_F,
        // DP_2D_NewF,
        DP_1D_F,
    };

public:
    int longestCommonSubsequence(string s, string t) {
        Method method{DP_1D_F};
        switch (method) {
            case DFS_MEMO: {
                return SolveDfsMemo(s, t);
            }
            case DP_1D_F: {
                return SolveDp1dF(s, t);
            }
        }
    }

private:
    // s[i] == t[j]: dfs(i, j) = dfs(i-1, j-1) + 1
    // s[i] != t[j]: dfs(i, j) = max(dfs(i, j-1), dfs(i-1, j))
    int SolveDfsMemo(string const& s, string const& t) {
        int n = s.length();
        int m = t.length();
        vector memo(n, vector(m, -1));  // 记忆数组 (n, m)
        auto dfs = [&](auto&& self, int i, int j) -> int {
            // 边界条件
            if (i < 0 || j < 0) {
                return 0;
            }
            auto& res{memo[i][j]};
            if (res != -1) {
                return res;
            }
            return res = (s[i] == t[j] ? self(self, i - 1, j - 1) + 1
                                       : max(self(self, i - 1, j), self(self, i, j - 1)));
        };
        return dfs(dfs, n - 1, m - 1);  // n - 1, m - 1
    }

    // 二维 f 数组:
    // s[i] == t[j]: f[i][j] = f[i-1][j-1] + 1
    // s[i] != t[j]: f[i][j] = max(f[i][j-1], f[i-1][j])
    // 偏移:
    // s[i] == t[j]: f[i+1][j+1] = f[i][j] + 1
    // s[i] != t[j]: f[i+1][j+1] = max(f[i+1][j], f[i][j+1])
    // 一维
    // s[i] == t[j]: f[j+1] = f[j] + 1
    // s[i] != t[j]: f[j+1] = max(f[j], f[j+1])
    int SolveDp1dF(string const& s, string const& t) {
        int n = s.length();
        int m = t.length();
        vector<int> f(m + 1);  // f 数组 (偏移后), f[0] 正好初始值也是 0
        for (auto x : s) {
            int pre{0};  // pre 存储左上方值, 会被覆盖(一开始就是 f[0])
            // 正序计算
            for (int j{0}; j < m; ++j) {  // NOTE: < m, 后面有 j + 1
                // 暂存下一次迭代要用的左上方值, 待会更新 pre
                // f[j+1] 是下一次的 pre
                int tmp = f[j + 1];
                // pre 是本次迭代的 f[i][j], 左上方值
                // f[j+1] 是本次计算出来的左边的值
                f[j + 1] = (x == t[j] ? pre + 1 : max(f[j], f[j + 1]));
                pre = tmp;  // 更新下一次左上方值
            }
        }
        return f[m];
    }
};
// @leet end

int main() { return 0; }
