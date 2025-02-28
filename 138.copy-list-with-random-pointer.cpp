#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

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
#if 1
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        // NOTE: 复制节点放在原链表两个节点之间
        // HACK: 以下的 next 其实都用来存放<旧>节点
        // 以下的 iter 其实都用来遍历<旧>节点
        auto iter{head};
        Node* next{nullptr};
        while (iter) {
            next = iter->next;
            iter->next = new Node{iter->val};
            iter->next->next = next;
            iter = next;
        }
        // NOTE: 根据以上新旧节点结构关系, 设置新节点 random 指针
        // HACK: 因为新旧节点 next 重叠, 但新节点 random 为空方便操作
        iter = head;
        Node* copy{nullptr};
        while (iter) {
            copy = iter->next;
            copy->random = iter->random ? iter->random->next : nullptr;  // NOTE: random 可能为空
            iter = copy->next;
        }

        // NOTE: 分离新旧节点
        auto copy_head{head->next};
        iter = head;
        while (iter) {
            copy = iter->next;  // 存储 copy
            next = copy->next;  // 存储下一个旧节点(可能到末尾就是 nullptr)
            iter->next = next;
            copy->next = next ? next->next : nullptr;  // NOTE: 最后旧节点为 nullptr
            iter = next;
        }
        return copy_head;
    }
#else
    // 哈希表(偷懒)
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        auto iter1{head};
        std::unordered_map<Node*, Node*> map;
        // 1. 创建复制链表的各个节点(next & random 先不设置)
        while (iter1) {
            map.insert({iter1, new Node{iter1->val}});
            iter1 = iter1->next;  // NOTE: 更新 iter
        }
        // 2. 设置 next 和 random 指针
        auto iter2{head};
        while (iter2) {
            map[iter2]->next = map[iter2->next];      // NOTE: 映射
            map[iter2]->random = map[iter2->random];  // NOTE: 映射
            iter2 = iter2->next;                      // NOTE: 更新 iter
        }
        return map[head];
    }
#endif
};
// @leet end

int main() {
    return 0;
}
