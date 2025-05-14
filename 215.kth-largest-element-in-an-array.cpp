#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 随机选择基准数字 p 注意是 rand()%nums.size()
// 划分 big equal small
// 递归 big small 最后返回 p

// @leet start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { return QuickSelect(nums, k); }

    int QuickSelect(vector<int>& nums, int k) {
        // 随机选择基准数字
        int p = nums[rand() % nums.size()];

        // 遍历 nums 划分 >, =, <
        vector<int> big, equal, small;
        for (auto& x : nums) {
            x > p ? big.push_back(x) : (x < p ? small.push_back(x) : equal.push_back(x));
        }
        // 第 k 大在 big 中
        if (k <= big.size()) {
            return QuickSelect(big, k);
        }

        // 第 k 大在 small 中
        if (k > big.size() + equal.size()) {
            return QuickSelect(small, k - big.size() - equal.size());  // NOTE: 这里得改 k
        }

        // 第 k 大在 equal 中
        return p;
    }
};
// @leet end

int main() { return 0; }
