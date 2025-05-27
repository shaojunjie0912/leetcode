#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 1. 数组仿照哈希表记录次数
// 2. 不定长滑窗

// @leet start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int curr_map[128]{};
        int ans{0};
        for (int l{0}, r{0}; r < s.size(); ++r) {
            ++curr_map[s[r]];
            // 如果<右>侧字符出现过, 则<左>端点一直右移
            while (curr_map[s[r]] > 1) {  // NOTE: 是 s[r]
                // NOTE:
                // 先左端点字符计数 - 1
                // 再左端点右移 + 1
                --curr_map[s[l]];
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
