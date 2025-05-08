#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 在区间 [0, n - 2] 二分, 跟数组最右边的数 nums[n - 1] 比较

// 红色: 最小值左侧
// 蓝色: 最小值及其右侧

// x > nums[n - 1]: x 在最小值左侧
// x <= nums[n - 1]: x 就是最小值或 x 在最小值右侧

// @leet start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 闭区间 [0, n - 2]
        int l = 0;
        int r = nums.size() - 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums.back()) {  // mid 在最小值左侧, 需要往右找
                l = mid + 1;
            } else {  // mid 在最小值右侧, 需要往左找
                r = mid - 1;
            }
        }
        // 思考: 这里的 l 有两种含义
        // 1. 如果找到红蓝边界, 则 l 就是答案
        // 2. 如果全都是红, 则 l 对应 n - 1 (肯定有一个最小值作为答案吧, 总不会没最小)
        return nums[l];
    }
};
// @leet end

int main() { return 0; }
