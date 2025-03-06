#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // 双指针法
    int removeElement(vector<int>& nums, int val) {
        int size{0};
        for (int slow = 0, fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] == val) {
                continue;
            }
            nums[slow++] = nums[fast];  // 别++fast了, 想清楚!
            ++size;
        }
        return size;
    }
};
// @leet end

int main() {
    return 0;
}
