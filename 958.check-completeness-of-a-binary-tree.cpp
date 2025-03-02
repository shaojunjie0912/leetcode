#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

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
    // NOTE: BFS, 遍历每一个节点, 以下两种情况返回 false
    // 1. 某个节点有右孩子没有左孩子
    // 2. 遇到过左右孩子不双全的节点后，又遇到了非叶子节点
    bool isCompleteTree(TreeNode* root) {
        if (!root->left && !root->right) {
            return true;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        // 子节点是否完整
        bool complete{true};  // NOTE: 该值为false后所有节点都必须为叶节点
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size--) {
                auto node{nodes.front()};
                nodes.pop();
                if ((!node->left && node->right) || (!complete && (node->left || node->right))) {
                    return false;
                }
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
                if ((!node->left) || (!node->right)) {
                    complete = false;
                }
            }
        }
        return true;
    }
};
// @leet end

int main() {
    return 0;
}
