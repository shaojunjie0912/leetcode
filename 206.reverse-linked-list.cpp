#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev{nullptr};
        ListNode* next{nullptr};
        // NOTE: head会到链表末尾nullptr, 条件head非空
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;  // HACK: 竟然忘了这个?最后肯定要移动更新curr到next啊!
        }
        return prev;  // NOTE: 返回prev
    }
};
// @leet end

int main() {
    return 0;
}
