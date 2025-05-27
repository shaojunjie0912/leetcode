#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
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

// p0: 区间 [left, right] 前一个节点
// 必须使用 dummy 作为当 left = 1 时的 p0
// 本题就是额外多了一个 p0, 要指向反转后的 right
// 之前反转用到的 prev curr next 还是一样的

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
    // NOTE: 反转结束后, 从原来的链表上看
    // prev 是反转段最后一个节点
    // curr 是反转段下一个节点
    // NOTE: 关键: 增加 p0: 反转段前一个节点
    // 防止 left = 1 特殊情况没有 p0, 因此使用哨兵节点作为一开始的 p0
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy{0, head};
        auto p0{&dummy};  // 哨兵节点作为一开始的 p0, 指向反转段前一个节点
        auto curr{head};
        int cnt{right - left + 1};  // 反转段节点个数
        while (--left) {            // p0 移动到 left - 1, curr 移动到 left
            p0 = p0->next;
            curr = curr->next;
        }

        ListNode* prev{nullptr};
        while (cnt--) {
            auto next{curr->next};
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // prev 是反转段最后一个节点
        // curr 是反转段下一个节点
        p0->next->next = curr;
        p0->next = prev;
        return dummy.next;
    }
};
// @leet end

int main() { return 0; }
