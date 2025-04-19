#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 回溯三问
// - 当前操作: 枚举 path[i] 要填入的字母
// - 子问题: 构造字符串 >= i 的部分 dfs(i)
// - 下一个子问题: 构造字符串 >= i+1 的部分 dfs(i+1)

// @leet start
class Solution {
public:
    // 数字 -> 字符数组映射
    string MAPPING[10]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) {  // 判空
            return {};
        }

        string path(n, 0);   // path 长度与 digits 相同
        vector<string> ans;  // 存储 paths

        // 递归 lambda 写法
        auto dfs = [&](auto&& self, int i) {  // NOTE: 注意写法
            // 边界条件
            if (i == n) {
                ans.push_back(path);
                return;
            }
            // 非边界条件
            for (char c : MAPPING[digits[i] - '0']) {  // 对应数组下标
                // 直接覆盖, 对应回溯: 删掉原来的再添加新的
                path[i] = c;
                self(self, i + 1);  // NOTE: 注意写法
            }
        };
        dfs(dfs, 0);  // NOTE: 注意写法, 且从 0 开始
        return ans;
    }
};
// @leet end

int main() {
    string digits = "23";
    Solution solution;
    vector<string> ans = solution.letterCombinations(digits);
    return 0;
}
