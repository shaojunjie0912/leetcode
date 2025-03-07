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
    // NOTE: 复制节点放在中间连线上
    // 思考: 涉及到节点交换才用到prev, 这题不要交换
    Node* copyRandomList(Node* head) {
        // HACK: 这里需要判空, 以后还是先判空吧, 保底一些
        if (!head) {
            return nullptr;
        }
        auto curr{head};
        Node* next{nullptr};
        // 先在中间连线创建复制节点
        while (curr) {
            next = curr->next;
            curr->next = new Node{curr->val};  // curr 连复制节点
            curr->next->next = next;           // 复制节点连 next
            curr = next;                       // 更新curr
        }
        // 此时copy和curr在一条线上
        // 再连上random指针(因为random指针并不会跟next指针重叠, 好处理)
        curr = head;
        auto copy{head->next};
        while (curr) {
            copy->random =
                curr->random ? curr->random->next : nullptr;  // HACK: 注意 random 可能是 nullptr
            curr = copy->next;                                // 更新curr
            copy = curr ? curr->next : nullptr;  // 更新copy(HACK: 注意curr可能到达 nullptr)
        }
        // 最后分割copy线和主线(即连上next指针)
        // Node* prev{nullptr};
        curr = head;
        auto copy_head{head->next};  // 提前先存一下copy_head(就是head->next)
        while (curr) {
            copy = curr->next;  // NOTE: 循环中的curr->next不会nullptr
            next = copy->next;  // NOTE: copy->next可能是nullptr
            curr->next = next;
            copy->next = next ? next->next : nullptr;
            curr = next;                         // 更新curr
            copy = next ? next->next : nullptr;  // NOTE: 更新copy(判空)
        }
        return copy_head;
    }

    // ========================= 旧的 =======================

    // Node* copyRandomList(Node* head) {
    //     if (!head) {
    //         return nullptr;
    //     }
    //     // NOTE: 复制节点放在原链表两个节点之间
    //     // HACK: 以下的 next 其实都用来存放<旧>节点
    //     // 以下的 iter 其实都用来遍历<旧>节点
    //     auto iter{head};
    //     Node* next{nullptr};
    //     while (iter) {
    //         next = iter->next;
    //         iter->next = new Node{iter->val};
    //         iter->next->next = next;
    //         iter = next;
    //     }
    //     // NOTE: 根据以上新旧节点结构关系, 设置新节点 random 指针
    //     // HACK: 因为新旧节点 next 重叠, 但新节点 random 为空方便操作
    //     iter = head;
    //     Node* copy{nullptr};
    //     while (iter) {
    //         copy = iter->next;
    //         copy->random = iter->random ? iter->random->next : nullptr;  // NOTE: random 可能为空
    //         iter = copy->next;
    //     }

    //     // NOTE: 分离新旧节点
    //     auto copy_head{head->next};
    //     iter = head;
    //     while (iter) {
    //         copy = iter->next;  // 存储 copy
    //         next = copy->next;  // 存储下一个旧节点(可能到末尾就是 nullptr)
    //         iter->next = next;
    //         copy->next = next?next->next:nullptr;  // NOTE: 最后旧节点为 nullptr
    //         iter = next;
    //     }
    //     return copy_head;
    // }
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
