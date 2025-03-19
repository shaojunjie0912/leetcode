#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: bfs 先进右 再进左, 最后一个节点就是最底层最左边节点

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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* node;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            node = nodes.front();
            nodes.pop();
            // NOTE: 不需要 while size--
            if (node->right) {
                nodes.push(node->right);
            }
            if (node->left) {
                nodes.push(node->left);
            }
        }
        return node->val;
    }
};
// @leet end

int main() {
    return 0;
}
