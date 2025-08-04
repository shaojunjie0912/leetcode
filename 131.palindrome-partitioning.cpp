#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 回溯
// - 输入角度 (位置 i 逗号选/不选 + start 子串开始位置)
// - 结果角度

// @leet start
class Solution {
    // 拆离判断回文字符串的函数 左->中<-右
    // left: 子串左端点
    // right: 子串右端点
    bool IsPalindrome(string_view s, int left, int right) {
        while (left <= right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

public:
#if 1
    // 输入角度: 选/不选 i 后面的逗号
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        // dfs 输入参数:
        // start: 子串开始位置
        // i: i 后面的逗号选/不选 (0, 1, 2, ..., n - 1) 第 n - 1 个逗号必须选
        // i 也是子串结束位置
        function<void(int, int)> dfs = [&](int start, int i) -> void {
            if (i == n) {  //
                ans.push_back(path);
                return;
            }

            // 不选 i 后面的逗号 (i = n - 1 时必须选, 这样才能和后面分割)
            if (i < n - 1) {
                dfs(i + 1, start);
            }

            // 选 (既然选了, 就开始分割并判断)
            if (IsPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));  // 加入 path
                // 递归 dfs, 枚举下一个子串
                dfs(i + 1, i + 1);  // start = i + 1 子串从 i + 1 开始
                path.pop_back();    // 恢复现场
            }
        };

        dfs(0, 0);
        return ans;
    }
#else
    // 答案角度: 枚举子串结束的位置
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        // dfs(i) 的 i 表示要枚举选 i 到 n-1 作为子串结束位置
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            // 枚举子串结束位置 (用 j 遍历 i 到 n - 1)
            for (int j = i; j < n; ++j) {
                if (IsPalindrome(s, i, j)) {
                    path.push_back(s.substr(i, j - i + 1));  // 分割
                    dfs(j + 1);                              // 剩余的 s[j+1] ~ s[n-1]
                    path.pop_back();                         // 恢复现场
                }
            }
        };

        dfs(0);
        return ans;
    }
#endif
};
// @leet end

int main() { return 0; }
