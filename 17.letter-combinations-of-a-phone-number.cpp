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
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {  // 判空
            return {};
        }

        int n = digits.size();
        string path(n, 0);  // (n, 0) 构造 path 长度与 digits 相同
        vector<string> ans;

        function<void(int)> dfs = [&](int i) -> void {
            // 边界条件, 记录答案
            if (i == n) {
                ans.push_back(path);
                return;
            }
            // 非边界条件, 理解这个 for 循环,
            for (char c : mapping[digits[i] - '0']) {
                // 枚举第 i 个字母 (直接覆盖就不需要恢复现场了)
                path[i] = c;  // 思考: 第 i 个字母选 a/b/c...?
                // 构造 >= i+1 的部分
                dfs(i + 1);  // 思考: 递归到 i+1, 也就是下一个字母, 在下一个 mapping[i+1] 中
            }
        };
        dfs(0);  // 递归入口
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
