#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 创建一个新的空链表,「头插法」依次在头部插入节点

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
        ListNode* curr{head};
        while (curr) {
            auto next{curr->next};  // 暂存 next
            curr->next = prev;
            prev = curr;
            curr = next; // !!暂存的 next!!
        }
        return prev;  // NOTE: 返回的是 prev, 此时 curr = nullptr
    }
};
// @leet end

int main() { return 0; }
