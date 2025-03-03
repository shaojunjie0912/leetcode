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
    // NOTE: 递归

    // 完成了x子树的遍历并返回后
    int g_yes;  // x子树在<偷头节点>的情况下的最大收益
    int g_no;   // x子树在<不偷头节点>的情况下的最大收益

    int rob(TreeNode* root) {
        R(root);
        return max(g_yes, g_no);
    }

    // 这里递归函数是void, 因为借助全局变量的更新
    void R(TreeNode* curr) {
        if (!curr) {  // 空树偷或者不偷头节点收益都是0
            g_yes = 0;
            g_no = 0;
            return;
        }
        int yes = curr->val;  // 当前节点自己的 yes(偷)
        int no = 0;           // 当前节点自己的 no(不偷)

        // 当前节点 + 左子树的最大收益 + 右子树最大收益
        R(curr->left);           // 更新 g_yes, g_no 为左子树的最大收益
        yes += g_no;             // 偷当前节点就不能偷孩子
        no += max(g_yes, g_no);  // 不偷当前节点就取子树最大值

        R(curr->right);  // 更新 g_yes, g_no
        yes += g_no;
        no += max(g_yes, g_no);
        // 更新当前整棵树的最大收益到 g_yes, g_no
        g_yes = yes;
        g_no = no;
        return;
    }
};
// @leet end

int main() {
    return 0;
}
