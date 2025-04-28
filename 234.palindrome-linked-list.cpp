#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 1. 找中间节点
// 2. 翻转右侧链表 (因为右侧有 nullptr, 所以可以用翻转套路)
// head -> ...-> middle_node <- ... <- right_head
//                   ↓
//                nullptr
// 相向双指针往中间移动并判断两边是否相等

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
    bool isPalindrome(ListNode* head) {
        auto middle_node{MiddleNode(head)};         // 中间节点
        auto right_head{ReverseList(middle_node)};  // 翻转中间节点到 nullptr 的链表
        while (right_head) {
            if (head->val != right_head->val) {
                return false;
            }
            head = head->next;
            right_head = right_head->next;
        }
        return true;
    }

private:
    // 获取链表中间节点
    ListNode* MiddleNode(ListNode* head) {
        auto slow{head}, fast{head};
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 翻转链表
    ListNode* ReverseList(ListNode* head) {
        ListNode* prev{nullptr};
        ListNode* curr{head};
        while (curr) {
            ListNode* next{curr->next};
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
// @leet end

int main() { return 0; }
