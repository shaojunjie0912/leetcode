#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;
// NOTE: 直接遍历?
// 注意: 左侧/右侧的和不包括当前元素

// @leet start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_sum = 0;
        int right_sum = std::accumulate(nums.begin(), nums.end(), 0);
        // NOTE: 注意以下逻辑对的
        // 右 sum 初始包含所有值, 应该减去当前元素
        // 左 sum 初始就是左侧的值, 判断完后, 再加上当前元素
        for (int i = 0; i < nums.size(); ++i) {
            // 右 sum 先减去当前值[i]
            right_sum -= nums[i];
            // 判断左/右 sum 是否相等
            if (left_sum == right_sum) {
                return i;
            }
            // 左 sum 再加上当前值[i]
            left_sum += nums[i];
        }
        return -1;
    }
    // int pivotIndex(vector<int>& nums) {
    //     int left_sum = 0;
    //     // NOTE: 减去了 nums[0] 因为是 0 索引右边的所有元素(不包括 [0])
    //     int right_sum = std::accumulate(nums.begin(), nums.end(), 0) - nums[0];
    //     if (right_sum == 0) {
    //         return 0;
    //     }
    //     for (int i = 1; i < nums.size(); ++i) {
    //         left_sum += nums[i - 1];  // NOTE: 左边加上的是[i-1]
    //         right_sum -= nums[i];     // NOTE: 右边减去的是[i]
    //         if (left_sum == right_sum) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
};
// @leet end

int main() {
    return 0;
}
