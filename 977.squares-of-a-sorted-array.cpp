#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.size() < 2) {
            return {nums[0] * nums[0]};
        }
        vector<int> res(nums.size(), 0);
        int l = 0;
        int r = nums.size() - 1;
// [ , )
#if 1
        int idx = res.size() - 1;
        while (l <= r) {
            int square_l = nums[l] * nums[l];
            int square_r = nums[r] * nums[r];
            if (std::abs(nums[l]) > std::abs(nums[r])) {
                res[idx--] = square_l;
                ++l;  // 只移 left
            } else {
                res[idx--] = square_r;
                --r;  // 只移 right
            }
        }
        return res;
#else
        // 1. 错误❌: 两个指针以相同速度往中间移动
        // 无法保证是正负对称的 (-3, -2, 1, 2)
        // 且奇数数组最中间那个元素会导致访问越界

        // 2. 优化: 结果数组的赋值索引从最大开始
        // 省去 std::reverse
        int idx = 0;
        while (l < r) {
            int square_l = nums[l] * nums[l];
            int square_r = nums[r] * nums[r];
            if (std::abs(nums[l]) > std::abs(nums[r])) {
                res[idx++] = square_l;
                res[idx++] = square_r;
            } else {
                res[idx++] = square_r;
                res[idx++] = square_l;
            }
            ++l;
            --r;
        }
        std::reverse(res.begin(), res.end());
        return res;
#endif
    }
};
// @leet end

int main() {
    return 0;
}
