#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
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

// NOTE: 本题需要 dummy, 因为头节点可能被删除

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy{0, head};
        auto curr{&dummy};
        // NOTE: 循环条件 curr->next 和 curr->next->next 均非空
        // 保证两个节点
        // dummy  head
        // curr   n1   n2  n3...
        while (curr->next && curr->next->next) {
            auto target_val{curr->next->next->val};
            if (curr->next->val == target_val) {
                // 删除所有值相同节点
                while (curr->next && curr->next->val == target_val) {
                    curr->next = curr->next->next;  // 修改 curr->next 指向下下一个
                }
            } else {
                curr = curr->next;  // 更新 curr 到 curr->next
            }
        }
        return dummy.next;
    }
};
// @leet end
