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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 额外变量 p0 用于后面指向反转后的 right
        ListNode dummy{0, head};
        auto p0{&dummy};
        for (int i{0}; i < left - 1; ++i) {  // p0 移动到 left - 1 处
            p0 = p0->next;
        }
        // 下面就是基本反转逻辑 (prev, curr, next)
        ListNode* prev{nullptr};
        auto curr{p0->next};                          // 这就是 left
        for (int i = 0; i < right - left + 1; ++i) {  // 最后 prev 在 right 位置, curr 在右边一个
            auto next{curr->next};
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 修改 left 从指向一开始的 prev(nullptr) 到指向 right 右边那个(现在的curr)
        p0->next->next = curr;
        // 修改 p0 从指向一开始的 left 到 right
        p0->next = prev;
        return dummy.next;
    }
};
// @leet end

int main() { return 0; }
