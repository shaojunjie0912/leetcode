#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
#if 1
    // 双指针法
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return slow;
    }
#else
    // 暴力双循环
    // 1for: 查找特定元素
    // 2for: 移动数组
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();  // 有效元素大小
        for (int i = 0; i < size; ++i) {
            if (nums[i] == val) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    nums[j - 1] = nums[j];
                }
                --i;  // 数组左移，因此 i 左移
                --size;
            }
        }
        return size;
    }
#endif
};
// @leet end

int main() {
    return 0;
}
