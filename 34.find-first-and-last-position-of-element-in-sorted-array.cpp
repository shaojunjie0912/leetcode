#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // begin: [..x-3,x,x,x,x+2...] 第一个 >= x
        int begin = LowerBound(nums, target);
        // 不符合条件直接返回:
        // 1. 全部都 < x, 没有 >= x 的
        // 2. 没有 == x 的
        if (begin == nums.size() || nums[begin] != target) {
            return {-1, -1};
        }
        // NOTE: end: [..x-3,x,x,x,x+2...] 第一个 >= x+1 的左边>那个数
        int end = LowerBound(nums, target + 1) - 1;
        // if (end == nums.size()) { // 不要判断了, 上面包括了
        //     end = nums.size() - 1;
        // }
        return {begin, end};
    }

private:
    // NOTE: 红蓝染色法?
    // 红: <
    // 蓝: >=
    // 循环结束后:
    // r: 红最后一个位置
    // l: 蓝第一个位置

    // 返回<有序数组>中满足 >=target 的最小索引
    // 如果没有, 则返回数组长度(NOTE: l 最终也就是数组长度)
    int LowerBound(vector<int>& nums, int target) {
        // 闭区间
        int l = 0;
        int r = nums.size() - 1;
        // 核心就是找红蓝边界
        while (l <= r) {
            int mid = l + (r - l) / 2;
            // 左侧都是红色 -> 答案肯定在右侧
            if (nums[mid] < target) {  // [mid] < target 情况
                l = mid + 1;           // 即此时 l-1(原来的 mid) 一定小于 target(红色)
            }
            // 右侧都是蓝色 -> 答案肯定在左侧
            else {            // [mid] >= target 情况 NOTE: 二分搜索中 == 被剥离了
                r = mid - 1;  // 此时 r+1(原来的 mid) 一定大于等于 target(蓝色)
            }
        }
        return l;
    }
};
// @leet end

int main() {
    return 0;
}
