#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 卡在不知道怎么转化为不定长滑动窗口
// NOTE: 由于要(或者说只能)删除一个元素, 则理解为: 滑窗内 0 的个数 <= 1
// 啊? 这都能过?(感觉只要转化没问题, 套路写法就能过)

// @leet start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans{0};
        int cnt_zero{0};
        for (int l{0}, r{0}; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                ++cnt_zero;
            }
            while (cnt_zero > 1) {
                if (nums[l] == 0) {
                    --cnt_zero;
                }
                ++l;
            }

            ans = max(ans, r - l);  // NOTE: 注意: 必须删除一个元素, 因此答案是滑窗大小 - 1
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
