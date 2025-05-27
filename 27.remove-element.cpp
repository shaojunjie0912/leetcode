#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // 双指针法
    int removeElement(vector<int>& nums, int val) {
        int slow{0}, fast{0};
        int n = nums.size();
        while (fast < n) {
            // 如果 fast 指向的元素不是 val
            // 则将其放到 slow 指向的位置
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return slow;  // slow 即为新数组的长度
    }
};
// @leet end

int main() { return 0; }
