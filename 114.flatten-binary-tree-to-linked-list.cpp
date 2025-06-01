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

// 法一: 递归 + 头插法
// 先递归右子树 -> 左子树 -> 中, 从从后往前插节点
// 要用到额外一个 TreeNode* prev 变量

// 法二: 分治

// dfs 返回链表的尾节点

// 1. 左子树链表尾节点连右子树链表头节点(即 node->right)
// left_tail->right = node->right;

// 2. node 连左子树头节点
// node->right = node->left;

// 3. 置空 node->left
// node->left = nullptr;

// dfs 最后返回的是合并后的链表尾节点, 即右链表尾节点 (right_tail)
// 如果 right_tail 为空, 则返回 left_tail, 如果 left_tail 也为空, 返回 nullptr

// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
#if 1
    // 法一: 递归 + 头插法
    TreeNode* prev{nullptr};
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        flatten(root->right);
        flatten(root->left);
        root->right = prev;    // 指向 prev
        root->left = nullptr;  // 题目要求: 左指针始终 nullptr
        prev = root;           // 更新 prev
    }
#else
    // 法二: 分治
    // dfs 返回链表的尾节点
    void flatten(TreeNode* root) {
        function<TreeNode*(TreeNode*)> dfs = [&dfs](TreeNode* node) -> TreeNode* {
            if (!node) {
                return nullptr;
            }
            auto left_tail = dfs(node->left);
            auto right_tail = dfs(node->right);

            if (left_tail) {  // 判空
                // 1. 左子树链表尾节点连右子树链表头节点(即 node->right)
                left_tail->right = node->right;
                // 2. node 连左子树头节点
                node->right = node->left;
                // 3. 置空 node->left
                node->left = nullptr;
            }
            return right_tail ? right_tail : left_tail ? left_tail : node;
        };
        dfs(root);
    }
#endif
};
// @leet end
