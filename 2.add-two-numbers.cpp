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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 辅助变量
        // ans: 结果链表头结点
        ListNode* ans = nullptr;
        // cur: 当前结点
        ListNode* cur = nullptr;
        // carry: 进位(0/1)
        int carry = 0;

        while (l1 || l2) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;  // 结点和+进位
            int val = sum % 10;                                         // %10
            carry = sum / 10;                                           // /10
            if (!ans) {
                ans = new ListNode{val};
                cur = ans;
            } else {
                cur->next = new ListNode{val};
                cur = cur->next;  // 更新结果链表遍历结点
            }
            l1 = l1 ? l1->next : nullptr;  // 更新链表一遍历结点
            l2 = l2 ? l2->next : nullptr;  // 更新链表二遍历结点
        }
        // 最后一步链表1和2都到末尾nullptr了, 跳出循环
        // <但如果有进位>则需要手动构造最后一个结点
        if (carry == 1) {
            cur->next = new ListNode{1};
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
