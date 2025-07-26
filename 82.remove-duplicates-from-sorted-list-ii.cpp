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
        auto curr{&dummy};                        // 这里 curr 其实是节点组(1, 2)前一个节点
        while (curr->next && curr->next->next) {  // 判断节点组(直到不满足俩个)
            auto val = curr->next->val;
            // 如果有重复的节点组
            if (val == curr->next->next->val) {
                // 值等于 val 的全部删除
                // 保证节点组节点存在
                while (curr->next && curr->next->val == val) {
                    curr->next = curr->next->next;
                }
            } else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
// @leet end
