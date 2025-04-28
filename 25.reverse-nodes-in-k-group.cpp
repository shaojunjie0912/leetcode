#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 三连击:
// 1. 反转整条链表
// 2. 反转部分链表
// 3. 反转多个部分链表

// p0 是区间左端点左边那个节点

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 统计节点个数 n, 方便在不足 k 时退出
        int n{0};
        for (auto curr{head}; curr; curr = curr->next) {
            ++n;
        }

        ListNode dummy{0, head};
        auto p0{&dummy};

        ListNode* prev{nullptr};
        auto curr{head};
        // k 个一组处理
        for (; n >= k; n -= k) {
            for (int i{0}; i < k; ++i) {  // 反转 k 个, 同: 一次反转部分链表
                auto next{curr->next};
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // 反转后, 原区间左端点指向 nullptr (最开始的 prev 初始值)
            // 所以要重新指向区间右端点右边那个 (其实就是现在的 curr)
            auto next{p0->next};    // p0->next 就是原左端点, 会变成下一轮反转的 p0
            p0->next->next = curr;  // p0->next 就是原左端点
            p0->next = prev;        // p0 要指向现在的 prev(即右端点)
            p0 = next;              // 更新 p0 NOTE: 因为多次反转部分, 因此需要更新 p0
        }

        return dummy.next;
    }
};
// @leet end

int main() { return 0; }
