#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// room 空位
// 本题没有移动元素要求, 因此不需要 swap, 直接用赋值

// @leet start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int room{0};
        for (auto& x : nums) {
            if (x != val) {
                nums[room++] = x;
            }
        }
        return room;
    }
};
// @leet end

int main() { return 0; }
