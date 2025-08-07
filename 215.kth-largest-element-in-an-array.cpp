#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
#if 1
    // 快速选择(时空复杂度都是 O(n))
    // 随机选择基准数字, 划分 big equal small
    int findKthLargest(vector<int>& nums, int k) {
        // 随机选择基准元素
        int p = nums[rand() % nums.size()];

        // 遍历 nums 与基准元素比较分 small(<p) equal(=p) big(>p) 子数组
        vector<int> big, equal, small;
        for (auto& x : nums) {
            x > p ? big.push_back(x) : (x < p ? small.push_back(x) : equal.push_back(x));
        }
        // 如果 k 小于 big 数组大小, 则说明第 k 大的元素在 big 中
        if (k <= big.size()) {
            return findKthLargest(big, k);
        }

        // 如果 k 大于 big + equal 数组大小之和, 则说明第 k 大的元素在 small 中
        if (k > big.size() + equal.size()) {
            return findKthLargest(small, k - big.size() - equal.size());  // NOTE: 这里得改 k
        }

        // 第 k 大在 equal 中 (即就是 p)
        return p;
    }
#else
    // 最小堆
    int findKthLargest(vector<int>& nums, int k) {
        // 维护大小为 k 的最小堆, 最终堆顶即第 k 大元素
        priority_queue<int, vector<int>, greater<int> > min_heap;
        for (auto& x : nums) {
            min_heap.push(x);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
#endif
};
// @leet end

int main() { return 0; }
