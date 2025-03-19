#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 搜索二叉树!!!
// 搜索二叉树(每个root节点): ..left.. < root < ..right..
// 没有重复值
// NOTE: 递归过程中不会遇到空节点的(根本递归不到叶节点)
// 和普通二叉树不同

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
        auto x{root->val};
        // p & q 都在左子树, 返回递归左子树结果
        if (p->val < x && q->val < x) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // p & q 都在右子树, 返回递归右子树结果
        if (p->val > x && q->val > x) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // 其余情况
        // p, q 分别在两棵子树中 -
        // 当前节点就是 p 或 q   ->  返回当前节点
        return root;
    }
};
// @leet end

int main() {
    return 0;
}
