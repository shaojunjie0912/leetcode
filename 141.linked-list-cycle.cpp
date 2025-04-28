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

// 快(2)慢(1)指针
// 若有环, 必相遇

// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow{head}, fast{head};
        while (fast && fast->next) {
            slow = slow->next;        // 走 1 步
            fast = fast->next->next;  // 走 2 步
            // NOTE: 判断放在走了 1 步 2 步后面
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
// @leet end
