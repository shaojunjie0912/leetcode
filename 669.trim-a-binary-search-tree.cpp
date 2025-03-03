#include <bits/stdc++.h>

#include "include/list_node.hpp"
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
    // NOTE: 搜索二叉树性质
    // 递归
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 终止条件(但也不能这样理解? 因为多处有 return)
        if (!root) {
            return nullptr;
        }
        // 当前值 < low, 整棵左子树都丢弃, 返回右子树结果
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        // 当前值 > high, 整棵右子树都丢弃, 返回左子树结果
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        // 如果当前值在范围内, 则当前 root 一定可以保留
        // 最终也会返回 root
        // 但是别急, NOTE: 先连上左子树和右子树修剪后结果
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @leet end

int main() {
    return 0;
}
