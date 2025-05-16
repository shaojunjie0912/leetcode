#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 1. dummy
// 2. carry: 节点和, 可以求出进位(carry / 10) 数位(carry % 10)
// 本题链表节点代表数位从低到高, 遍历过程自然可以进位

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
        ListNode dummy{};
        auto curr{&dummy};
        int carry{0};  // 进位
        while (l1 || l2 || carry) {
            if (l1) {              // 如果有 l1
                carry += l1->val;  // 加上 l1 节点值
                l1 = l1->next;
            }
            if (l2) {              // 如果有 l2
                carry += l2->val;  // 加上 l2 节点值
                l2 = l2->next;
            }
            // 1. 计算数位 (new 新节点)
            curr->next = new ListNode{carry % 10};
            curr = curr->next;
            // 2. 计算新的进位
            carry /= 10;
        }

        return dummy.next;
    }
};
// @leet end

int main() { return 0; }
