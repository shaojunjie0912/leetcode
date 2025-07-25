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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // NOTE: 空/单节点直接返回
        if (!head || !head->next) {
            return head;
        }
        // 计算总个数
        int n{0};
        for (auto curr{head}; curr; curr = curr->next) {
            ++n;
        }
        k %= n;
        // NOTE: 能被整除直接返回
        if (!k) {
            return head;
        };
        auto curr{head};
        for (int i = 0; i < n - k - 1; ++i) {
            curr = curr->next;
        }
        auto new_head{curr->next};
        curr->next = nullptr;
        curr = new_head;
        for (int i = 0; i < k - 1; ++i) {
            curr = curr->next;
        }
        curr->next = head;
        return new_head;
    }
};
// @leet end
