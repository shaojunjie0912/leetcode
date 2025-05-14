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
            while (curr_map[s[r]] > 1) {  // 如果右侧是重复字符, 则左端点一直右移
                // 思考: <左>端点右移是因为<右>端点之前出现过
                // 记得 --左端点字符计数
                --curr_map[s[l]];
                ++l;
            }
            ans = max(ans,
                      r - l + 1);  // 卡在没想到长度如何计算, 该放在循环后还是前
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
