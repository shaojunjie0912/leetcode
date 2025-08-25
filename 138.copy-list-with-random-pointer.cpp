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
        // NOTE: 判空
        if (!head) {
            return head;
        }

        auto curr{head};
        // 生成复制节点插到原节点后面
        while (curr) {
            auto next{curr->next};
            auto copy_node{new Node{curr->val}};
            curr->next = copy_node;
            copy_node->next = next;
            curr = next;
        }

        // 更新 random 链
        curr = head;
        while (curr) {
            // random 可能是 nullptr
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // 拆分 next
        auto copy_head{head->next};
        // n1 -> c1 -> n2 -> c2 -> ...
        // NOTE: 走到这里就说明 n1 c1 都存在了, 还要确保 n2 存在, 因为 n1 下一步跳到 n2
        curr = head;
        while (curr->next->next) {
            auto copy{curr->next};
            auto copy_next{copy->next};
            curr->next = copy_next;        // 原节点 next
            copy->next = copy_next->next;  // 新节点 next
            curr = curr->next;             // NOTE: 已经修改指向, 因此直接 curr->next
        }
        // NOTE: copy 链已经完成, curr 链还需要指向 nullptr
        curr->next = nullptr;

        return copy_head;
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
