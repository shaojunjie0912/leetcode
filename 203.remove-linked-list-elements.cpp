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

// NOTE: 删除链表节点需要知道前一个节点
// 所以: 1. 使用 dummy 兼容空节点; 2. 循环条件是 curr->next 非空

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy{0, head};

        auto curr{&dummy};
        while (curr->next) {
            auto nxt{curr->next};
            if (nxt->val == val) {
                // 删除
                curr->next = nxt->next;
                // 这里不要移动, 因为 next 可能也是 val, 防止漏删
                // 移动逻辑放在下面
            } else {
                curr = nxt;
            }
        }

        return dummy.next;
    }
};
// @leet end
