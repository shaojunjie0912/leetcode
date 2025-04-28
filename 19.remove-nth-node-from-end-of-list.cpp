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

// 1. 长度固定的尺子
// 左端点: head, 右端点: 左端点往右走 n 步
// 右端点到 nullptr 时, 左端点就是倒数第 n 个节点
// 由于要删除, 所以要倒数第 n + 1 个节点

// 2. 需要 dummy 应对 n = 链表长度的情况

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{};
        dummy.next = head;
        auto left{&dummy};  // 尺子左端点
        auto right{left};   // 尺子右端点

        // 移动尺子右端点 n + 1 步
        auto steps{n + 1};
        while (steps--) {
            right = right->next;
        }

        // 同时移动尺子左右端点, 直到右端点遇到 nullptr
        while (right) {
            left = left->next;
            right = right->next;
        }

        // 此时 left 是倒数第 n + 1 个节点, 用以删除倒数第 n 个节点
        left->next = left->next->next;
        return dummy.next;
    }
};
// @leet end
