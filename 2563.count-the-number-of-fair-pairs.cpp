#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 排序后二分
// 两个边界
// lower <= nums[i] + nums[j] <= upper
// lower - nums[i] <= nums[j] <= upper - nums[i]

// @leet start
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        int64_t ans{0};

        // it != end - 1 (因为 i < j )
        for (auto it{begin(nums)}; it != end(nums) - 1; ++it) {
            // HACK: lower/upper 不能累加被更改啊啊! 重新定义变量
            int new_lower = lower - *it;
            int new_upper = upper - *it;

            // NOTE: 傻孩子, 你只在 for 循环条件中考虑到了要从 it 后面找
            // 这里也要修改二分查找的范围呀!

            // 第一个 >= lower
            auto first_greater_lower{ranges::lower_bound(it + 1, end(nums), new_lower)};
            // 最后一个 <= upper
            auto last_less_upper{ranges::lower_bound(it + 1, end(nums), new_upper + 1) - 1};
            ans += last_less_upper - first_greater_lower + 1;
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
