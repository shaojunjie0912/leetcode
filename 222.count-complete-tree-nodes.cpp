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
    // HACK: 本题lc上有更简洁写法
    // NOTE: 本题是统计<完全>二叉树节点数
    // <满>二叉树节点数: 2^h -1, 其中 h 是高度
    // HACK: 递归
    // 1. 如果右子树的高度没有向下扎到左子树最底部, 那么右子树是满二叉树
    // 2. 如果扎到了, 则左子树是满二叉树
    // NOTE: 如果判断右子树的高度? 因为是完全二叉树, 所以看左/右子树最左节点
    int countNodes(TreeNode* root) {
        // HACK: 递归终止条件
        if (!root) {
            return 0;
        }
        // TODO: 叶子节点直接返回 1, 我也没想到
        if (!root->left && !root->right) {
            return 1;
        }
        // TODO: 如果没有右子节点, 那么显然没扎到(一开始我没想到)
        if (!root->right) {
            return 1 + countNodes(root->left);
        } else {
            int l_h{0};  // 左子树高度(子树, 不算 root)
            auto l_curr{root->left};
            while (l_curr) {
                ++l_h;
                l_curr = l_curr->left;
            }
            int r_h{0};  // 右子树高度(子树, 不算 root)
            auto r_curr{root->right};
            while (r_curr) {
                ++r_h;
                r_curr = r_curr->left;
            }
            if (r_h < l_h) {  // NOTE: 右子树没有扎到, 右子树为满二叉树
                return pow(2, r_h) + countNodes(root->left);  // 不算 root, r_h 不减 1
            } else {  // NOTE: 右子树扎到了, 左子树为满二叉树
                return pow(2, l_h) + countNodes(root->right);  // 不算 root, l_h 不减 1
            }
        }
    }
};
// @leet end

int main() {
    return 0;
}
