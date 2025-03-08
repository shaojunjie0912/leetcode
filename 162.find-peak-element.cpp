#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // 二分不断缩小范围, 在多个峰值中找到一个

    // 定理:
    // 1. 如果 i<n−1 且 nums[i]<nums[i+1], 则在下标 [i+1,n−1] 中一定存在至少一个峰值。
    // 2. 如果 i<n−1 且 nums[i]>nums[i+1], 那么在 [0,i] 中一定存在至少一个峰值。

    // 红色: 峰值元素左边
    // 蓝色: 峰值元素以及峰值元素右边

    int findPeakElement(vector<int>& nums) {
        int l = 0;
        // NOTE: 根据蓝色的定义, 最右边那个元素一定是蓝色, 所以未知区间不包括它
        int r = nums.size() - 2;  // size - 1 会栈溢出(因为下面 mid + 1, 数组访问越界)
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) {  // 左边一定有峰值
                r = mid - 1;
            } else {  // 右边一定有峰值
                l = mid + 1;
            }
        }
        return l;
    }
};
// @leet end

int main() {
    return 0;
}
