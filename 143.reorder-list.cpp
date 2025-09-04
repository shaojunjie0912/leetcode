#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
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
    ListNode* Middle(ListNode* head) {
        auto slow{head}, fast{head};
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* Reverse(ListNode* head) {
        ListNode* pre = nullptr;
        auto cur{head};
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

public:
    void reorderList(ListNode* head) {
        auto mid{Middle(head)};
        auto head2{Reverse(mid)};
        // head ... -> mid <- ... head2
        // NOTE: 不需要 curr 辅助变量, 本题不需要返回
        while (head2->next) {
            auto nxt{head->next};
            auto nxt2{head2->next};
            head->next = head2;  // NOTE: 这里是 head2
            head2->next = nxt;
            head = nxt;    // 直接更新 head 反正不需要返回
            head2 = nxt2;  // 直接更新 head2 反正不需要返回
        }
    }
};
// @leet end
