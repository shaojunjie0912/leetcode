#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
    enum Method {
        QuickSelectRecursive,
        MinHeap,
        QuickSelectIteration,
    };

public:
#if 1
    // 快速选择(递归)
    // 时间复杂度: O(n) 空间复杂度: O(n) NOTE: 可以改为原地 O(1) 空间复杂度
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

#elif 0
    // 最小堆
    // 时间复杂度: O(nlogk) 空间复杂度: O(k)
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

#else
    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        int target_idx = n - k;  // 第 k 大的元素，在升序排序后，索引是 n-k
        int left = 0, right = n - 1;

        // 使用静态的随机数生成器以获得更好的随机性
        static std::mt19937 gen(std::random_device{}());

        while (left <= right) {
            // 随机选择 pivot 并交换到当前子数组的开头
            std::uniform_int_distribution<int> distrib(left, right);
            int pivot_idx = distrib(gen);
            std::swap(nums[left], nums[pivot_idx]);

            int pivot_val = nums[left];
            int i = left;
            int j = right;

            // Hoare partition scheme 的变种
            while (i < j) {
                while (i < j && nums[j] >= pivot_val) {
                    j--;
                }
                while (i < j && nums[i] <= pivot_val) {
                    i++;
                }
                if (i < j) {
                    std::swap(nums[i], nums[j]);
                }
            }
            std::swap(nums[left], nums[i]);

            // 检查 pivot 的最终位置
            if (i == target_idx) {
                return nums[i];
            } else if (i < target_idx) {
                left = i + 1;  // 目标在右半部分
            } else {
                right = i - 1;  // 目标在左半部分
            }
        }
        return -1;  // 正常情况下不会执行到这里
    }
#endif
};
// @leet end

int main() { return 0; }
