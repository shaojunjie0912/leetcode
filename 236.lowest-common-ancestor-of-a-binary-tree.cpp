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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // NOTE: 递归, 两种情况:
    // 1. p&q 包含在一棵树内
    // 2. p,q 分叉在两棵树中
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果为null/p/q, 返回对应null/p/q
        if (!root || root == p || root == q) {
            return root;
        }
        auto l{lowestCommonAncestor(root->left, p, q)};   // 左递归
        auto r{lowestCommonAncestor(root->right, p, q)};  // 右递归

        // NOTE: p&q 包含在一棵树内会遇到的情况
        if (!l && !r) {
            return nullptr;  // HACK: l,r都没搜到返回空
        }

        //  NOTE: p,q 分叉在两棵树中会遇到的情况
        if (l && r) {
            return root;  // HACK: l,r都搜到返回p,q的父节点
        }

        // HACK: l/r 一个空一个不空
        // 返回 l/r 中不为空的那个
        return !l ? r : l;
    }
};
// @leet end

int main() {
    return 0;
}
