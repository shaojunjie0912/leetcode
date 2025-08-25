#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 归并排序(时间复杂度: O(nlogn), 空间复杂度: O(logn))
// 1. 链表中间节点 (快 2 慢 1, 要 prev 来断开跟 slow 的连接)
// 2. 合并两个有序链表 (dummy)
// 3. 递归调用 sortList

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
    ListNode* sortList(ListNode* head) {
        // NOTE: 这里边界条件是重要的, 后面递推退出, 0/1 个返回 head 不是 nullptr
        if (!head || !head->next) {  // 非空/一个节点, 返回 head
            return head;
        }
        auto head2{MiddleNode(head)};
        head = sortList(head);
        head2 = sortList(head2);
        return MergeTwoLists(head, head2);
    }

private:
    ListNode* MiddleNode(ListNode* head) {
        // 要断开中间节点跟前面那个节点的连接
        // 所以要记录 prev, 用 prev 断开跟 slow 的连接
        auto slow{head}, fast{head};
        ListNode* prev{nullptr};
        while (fast && fast->next) {  // fast 一次走俩步, 自然要额外判断 next
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;  // 断开 prev 和 slow 连接
        return slow;
    }

    ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy{};
        auto curr{&dummy};
        while (l1 && l2) {  // 条件是 l1 && l2
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        // 接上剩下部分
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
// @leet end

int main() { return 0; }
