#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int longestPalindrome(string s) {
        uint16_t s_map[128]{0};  // 出现次数
        int ans{0};
        // HACK: 如果是 1 则最后至多+1, 如果是3,5,7...直接加
        // 且删除原来的1, 即设为false吧, 只能加一个
        bool odd{false};
        for (auto& ch : s) {
            ++s_map[ch];
        }

        for (auto& cnt : s_map) {
            if (cnt == 0) {  // 跳过 0
                continue;
            }
            if ((cnt & 1) == 0) {  // 偶数直接加
                ans += cnt;
            } else {
                odd = true;  // NOTE: odd 记得加, 之前放到了里面==1分支
                // if (cnt == 1) { // 不需要了, 因为+1-1=0
                //     continue;
                // }
                ans += cnt - 1;  // HACK: 这里是奇数-1
            }
        }
        return odd ? 1 + ans : ans;
    }
};
// @leet end

int main() {
    return 0;
}
