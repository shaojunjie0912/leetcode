#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 快(2)慢(1)指针
// 如果有环:
// 1. slow(1) 和 fast(2) 相遇
// 2. 同时移动 head(1) 和 slow(1), 相遇点即入环点
// 如果无环:
// return nullptr

// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow{head}, fast{head};
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // 链表有环
            if (slow == fast) {
                while (slow != head) {
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        // 链表无环
        return nullptr;
    }
};
// @leet end

int main() { return 0; }
