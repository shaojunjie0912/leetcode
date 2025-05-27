#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 法 1: 最小堆
// - 合并后第 1 个节点一定是某个链表的头节点
// - 合并后的第 2 个节点可能是某个链表头节点, 也可能是第一个节点的下一个节点

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
#if 0
    // 方法一: 最小堆
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // NOTE: cmp 为 true 时会将 n2 排在前面
        auto cmp = [](ListNode* n1, ListNode* n2) { return n1->val > n2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

        // 所有非空链表头节点入堆
        for (auto head : lists) {
            if (head) {
                pq.push(head);
            }
        }

        ListNode dummy{};
        auto curr{&dummy};

        while (!pq.empty()) {     // 循环条件: 最小堆非空
            auto node{pq.top()};  // 取出
            pq.pop();
            if (node->next) {  // 如果有 next 则插入 next, 最小堆自动按照最小排序
                pq.push(node->next);
            }
            curr->next = node;  // curr 指向取出的node
            curr = curr->next;  // 更新 curr
        }

        return dummy.next;
    }
#else
    // 方法二: 递归
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return MergeKLists(lists, 0, n - 1);
    }

    // Merge lists[i]~lists[j]
    ListNode* MergeKLists(vector<ListNode*>& lists, int i, int r) {
        if (i > r) {
            return nullptr;
        }
        if (i == r) {
            return lists[i];
        }
        // 合并左边一半
        auto l1{MergeKLists(lists, i, i + (r - i) / 2)};
        // 合并右边一半
        auto l2{MergeKLists(lists, i + (r - i) / 2 + 1, r)};
        // 合并左右
        return Merge2Lists(l1, l2);
    }

    ListNode* Merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode dummy{};
        auto curr{&dummy};
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
#endif
};
// @leet end
