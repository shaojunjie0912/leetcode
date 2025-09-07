#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 在数量少的数组上二分(假设为 nums1)

// i 和 j 分割点分别将 nums1 和 nums2 分割为两部分

//             左     |   右
// nums1: 0, ..., i-1, i, ..., m-1
// nums2: 0, ..., j-1, j, ..., n-1

// nums1[0]...nums1[i-1], nums1[i]...nums1[m-1]

// nums2[0]...nums2[j-1], nums2[j]...nums2[n-1]

// 1. 数量守恒: i+j = (m+n+1)/2, 有 i 就可得 j
// 左半部分个数 = i + j
// 根据元素守恒: 合并 nums1 和 nums2 后左边一半数量是 (m+n+1)/2 (无论总数奇偶, 左半部分多一个)
// 因此 i+j = (m+n+1)/2

// 2. 交叉大小顺序正确 (左半部分最大值 <= 半部分最小值) NOTE: 这也是二分条件
// nums1[i-1] <= nums[j]
//          &&
// nums2[j-1] <= nums[i]

// 中位数在哪:
// 总数为奇数: 左半部分最大值
// 总数为偶数: (左半部分最大 + 右半部分最小)/2

// @leet start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {  // NOTE: 对较小数组二分
            return findMedianSortedArrays(nums2, nums1);
        }

        // NOTE: 查找分割点 i: 从 nums1 中取出前 i 个元素
        // 可以是 0 代表 0 个(没有), 可以是 m 代表 m 个(所有), 因此下面边界是 0~m/n
        int left = 0, right = m;  // HACK: 是 m!!! 不是 m-1
        while (left <= right) {
            // 二分计算 nums1 分割点 i
            int i = left + (right - left) / 2;
            // 根据元素守恒得到 nums2 分割点 j
            int j = (m + n + 1) / 2 - i;

            // 计算两组最大最小
            // NOTE: 分割点在边界的时候需要用极值(不要干扰)
            int left_max1 = i == 0 ? INT_MIN : nums1[i - 1];  // nums1 左边最大
            int right_min1 = i == m ? INT_MAX : nums1[i];     // nums1 右边最小 NOTE: 是 m

            int left_max2 = j == 0 ? INT_MIN : nums2[j - 1];  // nums2 左边最大
            int right_min2 = j == n ? INT_MAX : nums2[j];     // nums2 右边最小 NOTE: 是 n

            // 如果满足大小顺序条件 则代表分割正确
            if (left_max1 <= right_min2 && left_max2 <= right_min1) {
                // 根据奇偶计算中位数
                if ((m + n) % 2 == 1) {  // 奇
                    return max(left_max1, left_max2);
                } else {  // 偶
                    return (max(left_max1, left_max2) + min(right_min1, right_min2)) / 2.0;
                }
            } else if (left_max1 > right_min2) {  // i 太大了, 往左移动
                right = i - 1;
            } else {  // i 太小了, 往右移动(其实就是 left_max2 > right_min1 了)
                left = i + 1;
            }
        }
        return -1;
    }
};
// @leet end
