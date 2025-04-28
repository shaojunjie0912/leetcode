#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 技巧: 快(2)慢(1)指针
// 奇数: fast 到最后一个节点, slow 到中间节点
// 偶数: fast 到 nullptr, slow 到第二个中间节点
// 循环退出条件: fast == nullptr 或 fast->next == nullptr
// 返回 slow

// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto fast{head}, slow{head};
        while (fast && fast->next) {
            slow = slow->next;        // slow 每次 1 步
            fast = fast->next->next;  // fast 每次 2 步
        }
        return slow;
    }
};
// @leet end

int main() { return 0; }
