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
    // NOTE: 两个虚拟头结点(dum_small, dum_large)
    ListNode* partition(ListNode* head, int x) {
        auto dum_small{new ListNode{0}};
        auto dum_large{new ListNode{0}};
        auto curr_small{dum_small};
        auto curr_large{dum_large};
        // HACK: 循环里 head 一定非空, 那么 curr_small 和 curr_large 出来后需要置 next 空
        while (head) {
            if (head->val < x) {
                curr_small->next = head;
                curr_small = curr_small->next;
            } else {
                curr_large->next = head;
                curr_large = curr_large->next;
            }
            head = head->next;
        }
        // 接上small和large
        curr_small->next = dum_large->next;  // curr_small->next 指向 dum_large->next
        curr_large->next = nullptr;          // NOTE: 不要忘记curr_large->next置空
        // 释放资源?
        auto new_head{dum_small->next};
        delete dum_small;
        delete dum_large;
        return new_head;
    }

    // ListNode* partition(ListNode* head, int x) {
    //     if (!head) {
    //         return nullptr;
    //     }
    //     // 根据 x 划分左右区间
    //     // < x 区域
    //     ListNode* left_head = nullptr;
    //     ListNode* left_tail = nullptr;
    //     // >= x 区域
    //     ListNode* right_head = nullptr;
    //     ListNode* right_tail = nullptr;

    //     while (head) {
    //         ListNode* next = head->next;  // 临时存储下一个结点
    //         head->next = nullptr;         // 断连当前结点(最后一个结点本来就指向nullptr)
    //         if (head->val < x) {
    //             if (!left_head) {  // 如果当前左区间头为空
    //                 left_head = head;
    //             } else {
    //                 left_tail->next = head;  // 旧尾指向当前结点
    //             }
    //             left_tail = head;  // 旧尾移动到当前结点
    //         } else {
    //             if (!right_head) {
    //                 right_head = head;
    //             } else {
    //                 right_tail->next = head;
    //             }
    //             right_tail = head;
    //         }
    //         head = next;  // 使用之前存储的临时 next 更新 head
    //     }
    //     // 特殊情况: 左区间为空, 返回右头
    //     if (!left_head) {
    //         return right_head;
    //     }
    //     left_tail->next = right_head;  // 哪怕右区间为空也满足
    //     return left_head;
    // }
};
// @leet end

int main() {
    return 0;
}
