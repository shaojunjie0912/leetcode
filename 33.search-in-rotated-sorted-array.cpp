#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 二分 NOTE: 这里不能简单的直接用nums[mid]</>=target分区
// 要考虑数组被划分为了两个递增段

// [6,7,8,10,...0,1,2,3]
// 第一段, 第二段
// 在第一段还是第二段可以通过跟最右侧 nums[n-1] 比较(元素互不相同)

// 红色: nums[mid] 在 target 左侧(不是小于的意思)

// 蓝色: nums[mid] 就是 target 或在 target 右侧(不是大于的意思)
// - nums[mid] 在第一段, 则 target 必须在第一段, 且 target<=nums[mid]
// - nums[mid] 在第二段
//                         target 在第一段(满足)
//                      或 target 在第二段且 target <= nums[mid]

// 答案总在红蓝边界?(蓝区第一个元素)

// @leet start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 2;  // 最后一个元素一定是蓝色!
        // 确实要写个 check: 蓝色: true, 红色: false
        auto check = [&](int i) -> bool {
            int x = nums[i];
            // 最右边元素, 判断第1/2段
            int back = nums.back();
            if (x > back) {  // x 在第一段, 有以下对 target 要求
                return (target > back) && (target <= x);
            } else {  // x 在第二段, 有以下对 target 要求
                return (target > back) || ((target < back) && (target <= x));
            }
        };
        // 而且 l 最终可能要来到最后一个位置
        while (l <= r) {  // HACK: 我习惯闭区间[0, n-2]了, 开区间是(-1,n-1)
            int mid = l + (r - l) / 2;
            if (check(mid)) {  // 蓝色, 往左侧红色移动
                r = mid - 1;
            } else {  // 红色, 往右侧蓝色移动
                l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;  // 对nums[l]判断

        // NOTE: 在示例 2 中
        //  输入：nums = [4,5,6,7,0,1,2], target = 3
        //  算法最后 l = 0, 其实也就是边界! 神奇!
    }
};
// @leet end

int main() {
    return 0;
}
