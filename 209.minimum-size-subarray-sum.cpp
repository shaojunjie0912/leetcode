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
        int ans{INT_MAX};
        int n = nums.size();
        int l = 0;
        int sum = 0;
        for (int r = 0; r < n; ++r) {
            sum += nums[r];                    // 先加上右端点
            while (sum - nums[l] >= target) {  // 尽量缩小长度
                sum -= nums[l];
                ++l;
            }
            if (sum >= target) {  // sum >= target 才更新, 可以跳过
                ans = min(r - l + 1, ans);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @leet end

int main() { return 0; }
