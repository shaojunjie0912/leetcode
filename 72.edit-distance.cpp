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

// @leet start
class Solution {
    enum Method {
        DFS_MEMO,
        DP_2D_F,
        // DP_2D_NewF,
        DP_1D_F,
    };

public:
    int minDistance(string s, string t) {
        Method method{DP_1D_F};
        switch (method) {
            case DFS_MEMO: {
                return SolveDfsMemo(s, t);
            }
            case DP_2D_F: {
                return SolveDp2dF(s, t);
            }
            case DP_1D_F: {
                return SolveDp1dF(s, t);
            }
        }
    }

private:
    // s[i] == t[j]: dfs(i, j) = dfs(i-1, j-1)
    // s[i] != t[j]: dfs(i, j) = min(dfs(i, j-1), dfs(i-1, j), dfs(i-1,j-1)) + 1
    int SolveDfsMemo(string const& s, string const& t) {
        int n = s.length();
        int m = t.length();
        vector memo(n, vector(m, -1));  // 记忆数组
        auto dfs = [&](auto&& self, int i, int j) -> int {
            // NOTE: 边界条件 (有俩!)
            // 当 i/j < 0 时, 其中一个字符串为空, 那 t/s 剩下的[0, j/i]都得删除
            if (i < 0) {
                return j + 1;
            }
            if (j < 0) {
                return i + 1;
            }
            auto& res{memo[i][j]};
            if (res != -1) {
                return res;
            }
            // 相等就直接转到下一个(无需操作)
            // 不相等取三种操作(插入, 删除, 替换)最小
            // NOTE: 用 min({}) 支持多个操作数
            return res = (s[i] == t[j] ? self(self, i - 1, j - 1)
                                       : min({self(self, i, j - 1), self(self, i - 1, j),
                                              self(self, i - 1, j - 1)}) +
                                             1);
        };
        return dfs(dfs, n - 1, m - 1);
    }

    // 二维 f 数组:
    // s[i] == t[j]: f[i][j] = f[i-1][j-1]
    // s[i] != t[j]: f[i][j] = min(f[i][j-1], f[i-1][j], f[i-1][j-1]) + 1
    // 偏移:
    // s[i] == t[j]: f[i+1][j+1] = f[i][j]
    // s[i] != t[j]: f[i+1][j+1] = min(f[i+1][j], f[i][j+1], f[i][j]) + 1
    // NOTE: 注意初始值
    int SolveDp2dF(string const& s, string const& t) {
        int n = s.length();
        int m = t.length();
        // 默认初始化为 0, 而且f[0][0] 也是 0, s 和 t 都是空字符串
        vector f(n + 1, vector<int>(m + 1));  // f 数组 (带偏移)
        for (int j = 0; j < m; ++j) {
            // i = 0 时初始条件 (字符串数量确实是 j + 1, 但对应状态 f[j+1])
            f[0][j + 1] = j + 1;
        }
        for (int i = 0; i < n; ++i) {
            // j = 0 时初始条件 (字符串数量确实是 i + 1, 但对应状态 f[i+1])
            f[i + 1][0] = i + 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                f[i + 1][j + 1] =
                    (s[i] == t[j] ? f[i][j] : min({f[i][j + 1], f[i + 1][j], f[i][j]}) + 1);
            }
        }
        return f[n][m];
    }

    // s[i] == t[j]: f[i+1][j+1] = f[i][j]
    // s[i] != t[j]: f[i+1][j+1] = min(f[i+1][j], f[i][j+1], f[i][j]) + 1
    // 一维
    // s[i] == t[j]: f[j+1] = f[j]
    // s[i] != t[j]: f[j+1] = min(f[j], f[j+1], f[j]) + 1
    // NOTE: 最后一个 f[j] 是左上方值
    int SolveDp1dF(string const& s, string const& t) {
        int m = t.length();
        vector<int> f(m + 1);  // f[0] = 0
        for (int j = 0; j < m; ++j) {
            f[j + 1] = j + 1;  // 初始条件
        }
        for (char x : s) {
            int pre = f[0];
            ++f[0];
            for (int j = 0; j < m; ++j) {
                int tmp = f[j + 1];
                f[j + 1] = (x == t[j] ? pre : min({f[j], f[j + 1], pre}) + 1);
                pre = tmp;
            }
        }
        return f[m];
    }
};
// @leet end

int main() { return 0; }
