#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 组合型回溯

// 左括号等价于 "选"
// 右括号等价于 "不选"

// 记左右括号总数 2 * n, 分别需要 n 个

// 当前索引: i
// 当前左括号数量: open
// 当前右括号数量: i - open

// 妙在: 索引从 0 开始, 那么 i 可以代表 i 个括号, 数量对齐了

// 当左括号的数量 open < n, 就可以继续选左括号
// 当右括号的数量 i - open < open, 就可以继续选右括号

// @leet start
class Solution {
public:
#if 1
    // 选/不选
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(2 * n, 0);  // 这是 2 * n
        function<void(int, int)> dfs = [&](int i, int open) {
            // 边界条件: 这是 2 * n
            if (i == 2 * n) {
                ans.push_back(path);
                return;
            }

            // 不选
            if (i - open < open) {  // 还可以再选右括号
                path[i] = ')';      // 不选也要填右括号 '('
                dfs(i + 1, open);   // 继续递归 i+1, 左括号数量不变
            }

            // 选
            if (open < n) {  // 还可以再选左括号
                path[i] = '(';
                dfs(i + 1, open + 1);  // 继续递归 i+1, 左括号数量+1
            }
        };
        dfs(0, 0);  // 索引 0, 也正好 0 个左括号
        return ans;
    }
#else
    // 懒得写枚举哪一个了
    vector<string> generateParenthesis(int n) {}
#endif
};
// @leet end

int main() { return 0; }
