#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 回溯
// dfs(i): >= i 部分
// dfs(i+1): >= i+1

// @leet start
class Solution {
public:
    // 数字 -> 字符数组映射
    string mapping[10]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) {
            return {};
        }

        vector<string> ans;
        string path(n, 0);

        // 递归 lambda 写法
        auto dfs = [&](auto&& self, int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            for (char c : mapping[digits[i] - '0']) {  // 对应数组下标
                path[i] = c;                           // 直接覆盖(NOTE: 感觉对应回溯?)
                self(self, i + 1);
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
