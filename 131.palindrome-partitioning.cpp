#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
    bool IsPalindrome(string& s, int left, int right) {
        // 不需要 = 因为对于奇数, 中间那个就是对称轴
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        // 考虑 i 后面的逗号怎么选
        // start 表示当前这段回文子串的开始位置
        auto dfs = [&](auto&& self, int i, int start) {
            if (i == n) {  // s 分割完毕
                ans.emplace_back(path);
                return;
            }

            // 不选 i 和 i+1 之间的逗号（i=n-1 时一定要选）
            if (i < n - 1) {
                // 考虑 i+1 后面的逗号怎么选
                self(self, i + 1, start);
            }

            // 选 i 和 i+1 之间的逗号（把 s[i] 作为子串的最后一个字符）
            if (IsPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                // 考虑 i+1 后面的逗号怎么选
                // start=i+1 表示下一个子串从 i+1 开始
                self(self, i + 1, i + 1);
                path.pop_back();  // 恢复现场
            }
        };

        dfs(dfs, 0, 0);
        return ans;
    }
};
// @leet end

int main() { return 0; }
