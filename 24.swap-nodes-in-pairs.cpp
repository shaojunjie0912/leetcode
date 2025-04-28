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

// dummy 哨兵节点
// 画图:
// dummy(node0) -> node1 -> node2 -> node3 -> ... -> nullptr
// 上一个节点    (要交换的两个节点)
// 下一轮交换中, node1 变成上一个节点

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy{0, head};  // dummy 指向 head
        auto node0{&dummy};
        auto node1{head};
        // NOTE: 交换的是 node1 和 node1->next(即 node2)
        // 条件: 至少有两个节点
        while (node1 && node1->next) {
            auto node2{node1->next};
            auto node3{node2->next};
            node0->next = node2;  // 0 -> 2
            node2->next = node1;  // 2 -> 1
            node1->next = node3;  // 1 -> 3

            // 更新下一轮交换
            node0 = node1;
            node1 = node3;
        }
        return dummy.next;
    }
};
// @leet end
