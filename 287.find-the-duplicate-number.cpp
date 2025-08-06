#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 将 nums 想象成一个链表
// NOTE: 索引 i 代表链表的节点!!!!! 所以下面判断相同用的是节点即索引
// NOTE: nums[i] 的值是下一个节点的「地址」（即索引）

// 数组索引范围: [0, n]
// 值范围: [1, n]

// 鸽巢原理：我们有 n + 1 个“指针”（从 nums[0] 到 nums[n]），
// 但只有 n个可能的“目标位置”（从 1 到 n）。
// 根据鸽巢原理，必定至少有两个或以上的“指针”指向同一个“目标位置”。

// 判环, 寻找环的入口

// @leet start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;  // 这里初始化为相同的了, 下面肯定得先走一步
        // 肯定会相遇, 用 do while
        do {
            slow = nums[slow];        // slow 一步
            fast = nums[nums[fast]];  // fast 两步
        } while (slow != fast);  // 这里是判断 slow 和 fast

        // 相遇了
        slow = 0;
        // 这里是判断 slow 和 fast
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @leet end

int main() { return 0; }
