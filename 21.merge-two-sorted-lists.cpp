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
    // NOTE: 虚拟头结点 + 双指针遍历两条链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dum{new ListNode{0}};
        auto curr{dum};
        auto iter1{list1};  // 指针1
        auto iter2{list2};  // 指针2
        while (iter1 && iter2) {
            if (iter1->val < iter2->val) {
                curr->next = iter1;
                iter1 = iter1->next;  // HACK: !! 用了才更新 iter1
            } else {
                curr->next = iter2;
                iter2 = iter2->next;  // HACK: !! 用了才更新 iter2
            }
            curr = curr->next;  // 更新 curr
        }
        // NOTE: (不要忘了!!)最后肯定先有一个到nullptr
        curr->next = iter1 ? iter1 : iter2;
        // 资源释放?
        curr = nullptr;
        auto head{dum->next};
        delete dum;
        return head;
    }

    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if (!list1 || !list2) {
    //         return !list1 ? list2 : list1;
    //     }
    //     // 新头结点
    //     ListNode* head = list1->val <= list2->val ? list1 : list2;
    //     // 3 个辅助变量
    //     // cur1: 新头结点(其一个链表上)的下一个结点
    //     ListNode* cur1 = head->next;
    //     // cur2: 另外一个链表的头结点
    //     ListNode* cur2 = head == list1 ? list2 : list1;
    //     // prev: 已经挂好的结点
    //     ListNode* prev = head;
    //     // 循环: 当还没到两个链表的尾部时
    //     while (cur1 && cur2) {
    //         if (cur1->val <= cur2->val) {
    //             prev->next = cur1;  // 更新 prev->next, 挂上一个新结点
    //             cur1 = cur1->next;  // 更新 cur1
    //         } else {
    //             prev->next = cur2;  // 更新 prev->next, 挂上一个新结点
    //             cur2 = cur2->next;  // 更新 cur2
    //         }
    //         prev = prev->next;  // 更新 prev 到刚挂好的结点
    //     }
    //     // 当某个链表到达尾部时
    //     // 修改最后一个结点指向另外一个链表
    //     prev->next = cur1 ? cur1 : cur2;
    //     return head;
    // }
};
// @leet end

int main() {
    return 0;
}
