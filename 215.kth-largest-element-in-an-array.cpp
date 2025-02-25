#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 举例
        // 数值:             7 8 9
        // 索引/排序第 k 小: 0 1 2
        // 第 k 大:          3 2 1
        return RandomSelect(nums, nums.size() - k);
    }

    int Random(int min, int max) {
        // std::random_device 类重载了 ()
        // std::uniform_int_distribution 类重载了 ()
        std::mt19937 gen{std::random_device{}()};
        std::uniform_int_distribution<int> dist{min, max};
        return dist(gen);
    }
    // 随机选择算法
    // NOTE: 找到数组中排序在 i 位置的元素
    int RandomSelect(vector<int>& nums, int i) {
        int ans;
        int l = 0;
        int r = nums.size() - 1;
        while (true) {                   // NOTE: 这里边界条件之前写的是 l<=r, 感觉就是死循环
            int x = nums[Random(l, r)];  // NOTE: 索引取值
            auto [left, right] = Partition(nums, l, r, x);
            // 如果 i 在边界以左
            if (i < left) {
                r = left - 1;
            }
            // 如果 i 在边界以右
            else if (i > right) {
                l = right + 1;
            }
            // 否则, i 在边界中
            else {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }

    // 荷兰国旗
    std::pair<int, int> Partition(vector<int>& nums, int l, int r, int x) {
        int a = l;        // 左边界
        int b = r;        // 右边界
        int i = l;        // 循环遍历指针
        while (i <= b) {  // NOTE: 边界条件呢
            if (nums[i] < x) {
                std::swap(nums[i], nums[a]);
                ++a;
                ++i;
            } else if (nums[i] > x) {
                std::swap(nums[i], nums[b]);
                --b;
            } else {
                ++i;
            }
        }
        return {a, b};
    }
};
// @leet end

int main() {
    return 0;
}
