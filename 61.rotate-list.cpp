#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
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
    ListNode* rotateRight(ListNode* head, int k) {
        // NOTE: 链表判空, k 判 0
        if (!head || k == 0) {
            return head;
        }

        // 获取链表长度
        int len{0};
        auto curr{head};
        while (curr) {
            curr = curr->next;
            ++len;
        }

        // NOTE: 取余!! 取余后还要判 0
        if (k = k % len; k == 0) {
            return head;
        }

        // dummy -> ... -> 倒数第 k+1 个 -> new_head -> ... -> nullptr
        //                     l                                 r

        // 找到倒数第 k + 1 个节点, 指向 nullptr
        ListNode dummy{0, head};
        auto l{&dummy}, r{l};
        for (int i{0}; i < k + 1; ++i) {
            r = r->next;
        }
        while (r) {
            l = l->next;
            r = r->next;
        }
        // 此时 left 是倒数第 k + 1 个节点
        auto new_head{l->next};
        l->next = nullptr;

        // 修改最后一个节点指向
        curr = new_head;
        for (int i{0}; i < k - 1; ++i) {
            curr = curr->next;
        }
        curr->next = dummy.next;
        return new_head;
    }
};
// @leet end
