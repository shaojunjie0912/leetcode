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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
#if 0
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
    }
#else
    // 栈(偷懒, 占用内存大)
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        stack<ListNode*> stack;
        auto iter{head};
        // 入栈
        while (iter) {
            stack.push(iter);
            iter = iter->next;
        }
        // 出栈
        iter = head;
        while (iter) {
            auto top{stack.top()};
            stack.pop();
            if (top->val == iter->val) {
                iter = iter->next;
            } else {
                return false;
            }
        }
        return true;
    }
#endif
};
// @leet end

int main() {
    return 0;
}
