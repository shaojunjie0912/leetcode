#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 复制节点放在原节点连线中间

// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 判空
        if (!head) {
            return nullptr;
        }

        // 1. 复制 val (跳 2 步!!)
        // NOTE: 这里循环内改变了 curr->next 所以是跳 2 步
        for (auto curr{head}; curr; curr = curr->next->next) {
            // 复制新节点, 放在 curr 和 curr->next 之间
            curr->next = new Node{curr->val, curr->next, nullptr};
        }

        // 2. 复制 random (跳 2 步)
        for (auto curr{head}; curr; curr = curr->next->next) {
            // NOTE: random 判空
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        auto new_head{head->next};
        // 3. 分离 next
        for (auto curr{head}; curr; curr = curr->next) {
            auto copy{curr->next};
            curr->next = copy->next;                               // 恢复原节点的 next
            copy->next = curr->next ? curr->next->next : nullptr;  // 设置新节点的 next
        }

        return new_head;
    }
};
// @leet end

int main() {
    auto node2{new Node{2, nullptr, nullptr}};
    auto node1{new Node{1, node2, nullptr}};
    Solution s;
    s.copyRandomList(node1);
    delete node1;
    delete node2;
    return 0;
}
