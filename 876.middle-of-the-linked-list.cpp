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
    // NOTE: 技巧: 快(2)慢(1)指针
    // 奇数: fast 到最后一个节点, slow 到中间
    // 偶数: fast 到倒数第二个节点, slow 到中间第一个
    // 统一起来返回 slow: 则循环退出条件: fast==nullptr或 fast->next==nullptr
    ListNode* middleNode(ListNode* head) {
        auto fast{head};
        auto slow{head};
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @leet end

int main() {
    return 0;
}
