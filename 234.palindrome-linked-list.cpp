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
#if 1
    bool isPalindrome(ListNode* head) {
        // 快慢指针, 快指针: 2 步; 慢指针: 1 步
        // NOTE: slow 即中点

        // HACK: 一个节点也是
        if (!head->next) {
            return true;
        }

        // 1. 找到中点
        auto slow{head};
        auto fast{head};
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转右侧一半链表, 使其指向中点
        auto curr{slow};
        ListNode* prev{nullptr};  // 中间节点指向 nullptr
        ListNode* next{nullptr};

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 2. 比较左右两侧
        auto left{head};
        auto right{prev};
        auto ans{true};
        while (left && right) {
            if (left->val != right->val) {
                ans = false;
                break;
            }
            left = left->next;
            right = right->next;
        }

        // 3. 恢复原链表节点结构(从原尾即新右侧头开始)
        curr = prev;  // NOTE: prev 即最后一个节点
        prev = nullptr;
        next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return ans;
    }
#else
    // 栈(偷懒, 内存占用高)
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
