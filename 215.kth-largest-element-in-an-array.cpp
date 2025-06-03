#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
#if 1
    // 最小堆
    int findKthLargest(vector<int>& nums, int k) {
        // 维护大小为 k 的最小堆, 最终堆顶即第 k 大元素
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto& x : nums) {
            min_heap.push(x);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }

#else
    // 快速选择
    // 随机选择基准数字
    // 划分 big equal small
    // 递归 big small 最后返回 p
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
#endif
};
// @leet end

int main() { return 0; }
