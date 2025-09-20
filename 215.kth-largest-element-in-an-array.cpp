#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 随机选择算法
// 第 k 大: 第 n-k 小(基于 0-index)
// NOTE: 不能用 Partition 会退化到 n^2, 而且每次只能分两路
// 这道题必须用「三路分区」!!
// 整个区间: left = 0, right = n-1
// lt: 小区间的后一个
// gt: 大区间的前一个
// i: 当前处理的元素
// [left...lt-1]  < pivot
// [lt...i-1]     == pivot
// [i...gt]       未处理
// [gt+1...right] > pivot
// left...lt-1 lt...i-1 i...gt gt+1...right

// @leet start
class Solution {
public:
    // 快速选择
    // 时间复杂度: O(n) 空间复杂度: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        static std::mt19937 gen{std::random_device{}()};
        int n = nums.size();
        int target_idx = n - k;  // 第 k 大 = 第 n - k 小 (索引从 0 开始)
        int l = 0, r = n - 1;
        while (l <= r) {
            // 随机选择 pivot
            std::uniform_int_distribution<int> dist{l, r};
            std::swap(nums[dist(gen)], nums[l]);  // 把 pivot 换到最左边
            int pivot = nums[l];

            // 三路分区
            //    小区间     等于区间  未处理   大于区间
            // left...lt-1  lt...i-1  i...gt  gt+1...right
            int lt = l;  // lt: 指向“小于”部分的下一个位置
            int gt = r;  // gt: 指向“大于”部分的前一个位置
            int i = l;   // i: 当前遍历的元素指针

            // NOTE: 开始分区->注意循环条件
            while (i <= gt) {
                if (nums[i] < pivot) {  // 第一路
                    std::swap(nums[lt], nums[i]);
                    // NOTE: 左边的是旧 i 已经处理过了, 所以 lt 和 i 都 ++
                    ++lt;
                    ++i;
                } else if (nums[i] > pivot) {  // 第二路
                    std::swap(nums[i], nums[gt]);
                    // NOTE: 右边换过来的是新 i 还没处理, 所以只有 gt--
                    --gt;
                } else {  // 第三路
                    ++i;
                }
            }
            // NOTE: 接下来就是比较 target_idx 在哪个分区
            if (target_idx < lt) {  // 小分区
                r = lt - 1;
            } else if (target_idx > gt) {  // 大分区
                l = gt + 1;
            } else {  // 就在等于分区
                return pivot;
            }
        }
        return -1;
    }
};
// @leet end

int main() { return 0; }
