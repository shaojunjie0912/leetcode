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
    bool is_balance{true};  // 辅助变量(当不满足条件则变为false)

public:
    // NOTE: 平衡二叉树: 左/右子树高度相差 <= 1
    // 递归
    bool isBalanced(TreeNode* root) {
        R_Height(root);
        return is_balance;
    }

    // 返回高度的递归函数(这里面会修改 is_balance)
    int R_Height(TreeNode* curr) {
        // HACK: 之所以递归条件加上 is_balance
        // 是因为如果已经不平衡了, 没必要再递归求高度
        // 赶紧一层一层递归返回
        if (!is_balance || !curr) {
            return 0;
        }
        int l_h{R_Height(curr->left)};
        int r_h{R_Height(curr->right)};
        // HACK: 是否修改 is_balance
        if (std::abs(l_h - r_h) > 1) {
            is_balance = false;
        }
        // NOTE: 二叉树高度: max(左子树高度, 右子树高度) + 1
        return std::max(l_h, r_h) + 1;
    }
};
// @leet end

int main() {
    return 0;
}
