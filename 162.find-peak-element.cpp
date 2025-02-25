#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = -1;
        // 数组长度为 1 直接返回索引 0
        if (nums.size() < 2) {
            return 0;
        }
        // 验证第一个元素是否为峰值
        if (nums[0] > nums[1]) {
            return 0;
        }
        // 验证最后一个元素是否为峰值
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
            return nums.size() - 1;
        }
        // 中间 (1, n-2) 一定有峰值点
        int l = 1;
        int r = nums.size() - 2;
        // 二分法[]双闭区间
        while (l <= r) {
            int m = l + (r - l) / 2;
            // 如果中点是峰值, 则退出循环, 直接返回
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
                ans = m;
                break;
            } else if (nums[m] < nums[m - 1]) {
                // nums[m-1] -> nums[m] 下降趋势
                // 左边有峰值点
                r = m - 1;
            } else if (nums[m] < nums[m + 1]) {
                // nums[m-1] -> nums[m] 下降趋势
                // 右边有峰值点
                l = m + 1;
            }
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
