#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 不定长滑动窗口

// @leet start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len{INT_MAX};  // NOTE:
        int curr_sum{0};
        for (int l{0}, r{0}; r < nums.size(); ++r) {
            curr_sum += nums[r];
            while (curr_sum >= target) {  // 更新长度写在while里面那么条件就不用先减去l
                // 先保存此时长度, 不然你就把当前长度丢了
                min_len = min(min_len, r - l + 1);
                // 再右移左边界
                curr_sum -= nums[l++];
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
// @leet end

int main() {
    return 0;
}
