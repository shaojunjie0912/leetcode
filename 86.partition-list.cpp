#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE:
// 两个哨兵节点 small_dummy, large_dummy

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
    ListNode* partition(ListNode* head, int x) {
        ListNode small_dummy{}, large_dummy{};
        auto small{&small_dummy}, large{&large_dummy};

        auto curr{head};
        while (curr) {
            if (curr->val < x) {
                small->next = curr;
                small = small->next;
            } else {
                large->next = curr;
                large = large->next;
            }
            curr = curr->next;
        }

        small->next = large_dummy.next;
        large->next = nullptr;

        return small_dummy.next;
    }
};
// @leet end

int main() { return 0; }
