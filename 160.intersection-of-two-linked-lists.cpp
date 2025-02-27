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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // NOTE: 长链表先走 diff 步, 短链表再走, 一定在相交的起始节点
        // NOTE: 相交单链表最后一定是相同节点
        if (!headA || !headB) {
            return nullptr;
        }
        int diff{0};  // 理解为"步", 节点之间的连线, 不是节点个数(差1个)
        auto a{headA};
        auto b{headB};

        while (a->next) {
            a = a->next;
            ++diff;  // diff 自增
        }
        while (b->next) {
            b = b->next;
            --diff;  // diff 自减
        }

        // 上面如果不判断 -> next 则这里判断都是nullptr了
        // 此处为链表最后一个节点
        if (a != b) {  // HACK: 如果最后一个节点不相同, 则必不相交
            return nullptr;
        }
        if (diff > 0) {
            a = headA;  // A 长
            b = headB;  // B 短
        } else {
            a = headB;  // B 长
            b = headA;  // A 短
            // HACK: diff 取绝对值
            diff = std::abs(diff);
        }
        // NOTE: 长链表先走 diff 步
        while (diff > 0) {
            a = a->next;
            --diff;
        }
        // NOTE: 长短链表再一起走
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
// @leet end

int main() {
    return 0;
}
