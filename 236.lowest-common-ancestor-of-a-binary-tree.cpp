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
        // 如果当前节点为 null/p/q, 返回对应 null/p/q
        if (!root || root == p || root == q) {
            return root;
        }
        auto l{lowestCommonAncestor(root->left, p, q)};   // 左递归
        auto r{lowestCommonAncestor(root->right, p, q)};  // 右递归

        // NOTE: p,q 分别在两棵子树中: 返回当前节点
        if (l && r) {
            return root;
        }
        // 只有左边有: 返回左边递归结果
        if (l) {
            return l;
        }
        // 只有右边有: 返回右边递归结果
        else {
            return r;
        }
    }
};
// @leet end

int main() {
    return 0;
}
