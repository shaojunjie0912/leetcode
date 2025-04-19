#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 组合/子集型回溯两种做法:
// - 选或不选
// - 枚举选哪个

// 组合型回溯?
// 左括号等价于 "选"
// 右括号等价于 "不选"
// 记左右括号总数 2 * n, 分别需要 n 个
// 当前索引 i, 当前左括号数量 open, 当前右括号数量 i - open
// 当左括号的数量 open < n, 就可以继续选左括号
// 当右括号的数量 i - open < open, 就可以继续选右括号

// @leet start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int m = 2 * n;
        vector<string> ans;
        string path(m, 0);
        auto dfs = [&](auto&& self, int i, int open) {
            // 边界条件
            if (i == m) {
                ans.push_back(path);
                return;
            }
            if (open < n) {  // 还可以再选左括号
                path[i] = '(';
                self(self, i + 1, open + 1);  // 继续递归 i+1, 左括号数量+1
            }
            if (i - open < open) {  // 还可以再选右括号
                path[i] = ')';
                self(self, i + 1, open);  // 继续递归 i+1, 左括号数量不变
            }
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};
// @leet end

int main() { return 0; }
