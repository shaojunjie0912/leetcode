#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 将 nums 想象成一个链表, 判环, 寻找环的入口
// NOTE: 索引 i 代表链表的节点!!!!! 所以下面判断相同用的是节点即索引
// NOTE: nums[i] 的值是下一个节点的「地址」（即索引）

// 数组索引范围: [0, n]
// 值范围: [1, n]

// 鸽巢原理：我们有 n + 1 个“指针”（从 nums[0] 到 nums[n]），
// 但只有 n个可能的“目标位置”（从 1 到 n）。
// 根据鸽巢原理，必定至少有两个或以上的“指针”指向同一个“目标位置”。

// @leet start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow{0}, fast{0};
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {  // 第一次相遇, slow 回到原点
                slow = 0;
                while (slow != fast) {
                    slow = nums[slow];  // slow 步数改为 1
                    fast = nums[fast];
                }
                return slow;
            }
        }
    }
};
// @leet end

int main() { return 0; }
