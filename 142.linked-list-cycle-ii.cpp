#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

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
#if 1
    ListNode *detectCycle(ListNode *head) {
        // NOTE: 直接背!
        // ==============================================
        // 快慢指针(快 2 慢 1)
        // 1. 如果快指针遇到 nullptr 则一定不是环
        // 2. 第一次相遇时, 快指针返回起点, 速度由 2 -> 1
        // 3. 第二次相遇就是入环第一个节点
        // ==============================================

        // 0/1个节点都不是, 且排除2指向 null 的
        // NOTE: 为了下面的slow和fast不相等的循环条件
        if (!head || !head->next || !head->next->next) {
            return nullptr;
        }
        auto slow{head->next};
        auto fast{head->next->next};
        while (slow != fast) {                       // HACK: 原来slow&fast都是head就不对了
            if (!fast->next || !fast->next->next) {  // NOTE: 注意顺序
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
#else
    // 哈希集合(偷懒)
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {  // 0/1 个节点都不是
            return nullptr;
        }
        std::unordered_set<ListNode *> set;
        while (head) {
            if (!set.contains(head)) {
                set.insert(head);
            } else {
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }
#endif
};
// @leet end

int main() {
    return 0;
}
