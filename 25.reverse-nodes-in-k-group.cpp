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

// NOTE: 按 k 个一组翻转跟翻转整条链表不同
// 每组头节点翻转后指向下一组开始节点, 而不是一开始的nullptr
// HACK: 下组头 -> 下下组头(就是更新 last_team_end)
// 上组头 -> 下组尾

// Reverse(s1, e1) 前: s1->e1 -> s2->e2 -> s3->e3
// Reverse(s1, e1) 后: s1<-e1  s2->e2 -> s3->e3
//                     |_______↑
//              last_team_end

// Reverse(s2, e2) 后:
// 1. 需要将 s1(原 last_team_end) -> e2(即修改last_team_end->next)
// 2. 再更新 last_team_end -> s2

// s1<-e1  s2<-e2   s3->e3
// |_______|____↑   ↑
//         |________|
//    last_team_end

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto start{head};
        auto end{TeamEnd(start, k)};
        if (!end) {
            return head;
        }
        // 第一组特殊处理(需要返回头节点)
        head = end;
        Reverse(start, end);

        auto last_team_end{start};  // 翻转后 start 即上一组尾节点
        while (last_team_end->next) {
            start = last_team_end->next;
            end = TeamEnd(start, k);
            if (!end) {
                return head;
            }
            Reverse(start, end);
            last_team_end->next = end;
            last_team_end = start;
        }

        return head;
    }

    // 辅助函数
public:
    // 从 s 开始找第 k 个节点(包括 s 在内)
    // HACK: 即该组最后一个节点
    ListNode* TeamEnd(ListNode* s, int k) {
        // 因为包含 iter 因此 --k 前缀递减
        while (--k && s) {
            s = s->next;
        }
        return s;  // NOTE: 如果个数不够这里会返回 nullptr
    }

    // 翻转当前组节点
    // HACK:
    // s -> a -> b -> c -> e -> 下一组的开始节点
    //             reverse ↓
    // e -> c -> b -> a -> s -> 下一组的开始节点
    void Reverse(ListNode* s, ListNode* e) {
        e = e->next;  // 保存下一组开始节点

        // HACK: 翻转链表固定辅助变量?
        // 普通翻转只要 prev 和 next, s 会改变
        // 这里需要 curr 是因为 s 不能变, 最后要指向下一组开始节点
        ListNode* prev{nullptr};
        ListNode* curr{s};
        ListNode* next{nullptr};

        // NOTE: 循环条件
        // NOTE: 反转逻辑!!!
        while (curr != e) {  // HACK: 这里 e 之前已经变成 e->next 了
            next = curr->next;
            curr->next = prev;
            prev = curr;  // 更新 prev
            curr = next;  // 更新 curr
        }

        s->next = e;  // 指向下一组开始节点
    }
};
// @leet end

int main() {
    return 0;
}
