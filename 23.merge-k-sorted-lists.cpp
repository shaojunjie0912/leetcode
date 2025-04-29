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
    // 最小堆
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 最小堆
        auto cmp = [](ListNode* node1, ListNode* node2) { return node1->val > node2->val; };
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
};
// @leet end
