#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 将空节点加入考虑, 兼容不相交的情况
// 假设链表 A 额外长度为 x, 链表 B 额外长度为 y, 相交部分长度为 z
// 有 (x + z) + y = (y + z) + x
// 当 A 走到 nullptr 时, 跳到 B 的 head 再走 y 步
// 当 B 走到 nullptr 时, 跳到 A 的 head 再走 x 步
// 一定相遇!! (如果相遇节点是空节点, 则不相交)

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
        auto p{headA};
        auto q{headB};
        while (p != q) {
            p = p ? p->next : headB;  // 当 A 走到 nullptr 时, 跳到 B 的 head 继续走
            q = q ? q->next : headA;  // 当 B 走到 nullptr 时, 跳到 A 的 head 继续走
        }
        return p;
    }
};
// @leet end

int main() { return 0; }
