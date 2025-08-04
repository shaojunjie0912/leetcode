#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 排列型回溯

// NOTE: 条件 1: 一定是每一行每一列恰好一个皇后
// 由 on_col 数组保证

// on_col: 标记 0 ~ n - 1 列索引是否被选过

// NOTE: 条件 2: 不能同一斜线
// 由 diag1 和 diag2 数组保证

// 主对角线之和数组: diag1(2n - 1)
// 所有主对角线上 r + c 之和均匀分布在 (0, 0) 到 (n-1, n-1) 即 [0, 2n-2] 之间
// 一共 2n - 1 个数

// 副对角线之差数组: diag2(2n - 1)
// 所有副对角线上 r - c 之差均匀分布在 (0, n-1) 到 (n-1, 0) 即 [-(n-1), n-1] 之间
// 避免负数做一下偏移得到: [0, 2n - 2]
// 一共 2n - 1 个数

// 遍历 c 从 0 ~ n - 1
// 标记 -> 放皇后 -> 递归 i + 1 -> 取消标记

// @leet start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<int> col(n);            // 皇后位置 (r, col[r]) (path)
        vector<int> on_col(n);         // 标记列索引是否出现过 (on_path)
        vector<int> diag1(2 * n - 1);  // 标记主对角线之和是否出现过
        vector<int> diag2(2 * n - 1);  // 标记副对角线之差(偏移)是否出现过

        // r: 行索引
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {  // 抵达边界, 保存答案
                // 生成包含字符串 '..Q..' 的棋盘
                vector<string> board(n);
                // 遍历每行
                for (int r = 0; r < n; ++r) {
                    board[r] = string(col[r], '.') + 'Q' + string(n - col[r] - 1, '.');
                }
                ans.push_back(std::move(board));
                return;  // NOTE: 别代码一多就忘记 return
            }

            // (r, c[0, ..., n-1]) 遍历 c 从 0 到 n - 1
            // c: 列索引
            for (int c = 0; c < n; ++c) {
                int sum_rc = i + c;           // rc 和
                int diff_rc = i - c + n - 1;  // rc 差

                // 限制 1: 不在同一列;
                // 限制 2: 不在同一斜线(主/副对角线)
                if (!on_col[c] && !diag1[sum_rc] && !diag2[diff_rc]) {
                    on_col[c] = diag1[sum_rc] = diag2[diff_rc] = 1;  // 标记为已访问
                    col[i] = c;                                      // NOTE: 皇后位置: r 行 c 列
                    dfs(i + 1);                                      // 继续递归
                    on_col[c] = diag1[sum_rc] = diag2[diff_rc] = 0;  // 恢复现场
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @leet end

int main() { return 0; }
