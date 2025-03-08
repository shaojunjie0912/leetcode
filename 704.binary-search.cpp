#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 二分红蓝染色法

// LowerBound(其实C++20有ranges::lower_bound>=, 以及upper_bound>)
// 红: nums[mid] < target
// 蓝: nums[mid] >= target

// 对于 [0, n-1] 二分, 最终 l 到 n
// 意味着最后返回 l 要<额外>再做一个判断是否等于 n, 代表是否搜索到
// 搜索到了再判断 nums[l] 是否是 target 即可

// NOTE: 灵神说区间改为 [0, n-2], 这样最终 l 来到 n-1,
// 只要判断 nums[l] 是否是 target 即可

// @leet start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = LowerBound(nums, target);
        return (l < nums.size() && nums[l] == target) ? l : -1;  // [0, n-1] 要判断 2 个条件
        // return (nums[l] == target) ? l : -1;                     // [0, n-2] 只要 1 个条件
    }

private:
    int LowerBound(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;  // [0, n-1]
        // int r = nums.size() - 2; // [0, n-2]
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {  // 当前及右边是蓝色, 需要往左
                r = mid - 1;
            } else {  // 当前及左边是红色, 需要往右
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
