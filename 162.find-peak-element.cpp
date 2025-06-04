#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 二分不断缩小范围, 在多个峰值中找到一个

// 定理:
// 1. 如果 i<n−1 且 nums[i]<nums[i+1], 则在下标 [i+1,n−1] 中一定存在至少一个峰值。
// 2. 如果 i<n−1 且 nums[i]>nums[i+1], 那么在 [0,i] 中一定存在至少一个峰值。

// 红色: 峰值元素左边
// 蓝色: 峰值元素以及峰值元素右边

// @leet start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // NOTE: 根据蓝色的定义, 最右边那个元素一定是蓝色, 所以未知区间不包括它
        int l = 0, r = n - 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @leet end

int main() { return 0; }
