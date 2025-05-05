#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 递归, 分情况:
// 当前节点是空节点 -
// 当前节点是 p     -> 返回当前节点
// 当前节点是 q     -
// 其他:
//      p,q 分别在两棵子树中: 返回当前节点
//      p&q 都在左子树: 返回递归左子树的结果
//      p&q 都在右子树: 返回递归右子树的结果
//      p&q 不在任何子树: 返回空节点

// 思考: 递归返回的不是 p/q 而是结果, 我一开始错以为是 p / q 了还在想应该返回先找到的那个

// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1. 当前节点是空节点 / 就是 p / 就是 q
        if (!root || root == p || root == q) {
            return root;
        }

        // 2. 其他情况 (递归左右子树)
        auto left{lowestCommonAncestor(root->left, p, q)};
        auto right{lowestCommonAncestor(root->right, p, q)};

        // 2.1 左右子树都找到: 返回当前节点
        if (left && right) {
            return root;
        }
        // 2.2 只有左子树找到
        // 2.3 只有右子树找到
        // 2.4 左右子树都没找到
        return left ? left : right;  // 包含了 nullptr
    }
};
// @leet end

int main() { return 0; }
