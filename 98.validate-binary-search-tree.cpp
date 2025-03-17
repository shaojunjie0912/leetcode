#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 搜索二叉树(每个节点): ..left.. < root < ..right..

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
    bool isValidBST(TreeNode* root) {
        // HACK: 用int64_t, 防止INT_MIN, INT_MAX
        // return PreR(root, INT64_MIN, INT64_MAX);
        return InR(root);
    }

private:
#if 0
    // 前序遍历递归, 传入节点同时, 传入开区间范围(left, right)
    // HACK: 关键: left < val < right
    bool PreR(TreeNode* root, int64_t left, int64_t right) {
        if (!root) {  // 终止条件: 空节点
            return true;
        }
        int64_t x = root->val;
        // 1. 当前节点满足条件
        // 2. 左子树满足条件(更新右边界为 x)
        // 3. 右子树满足条件(更新左边界为 x)
        return left < x && x < right && R(root->left, left, x) && R(root->right, x, right);
    }
#elif 1
    // 中序遍历递归
    // 思考: 中序遍历的结果就是一个递增数组
    // HACK: 关键: prev_val < curr_val
    int64_t pre = INT64_MIN;
    bool InR(TreeNode* root) {
        if (!root) {
            return true;
        }
        // 左
        if (!InR(root->left)) {
            return false;
        }
        // 中
        if (root->val <= pre) {
            return false;
        }
        pre = root->val;
        // 右
        return InR(root->right);
    }
#else
    // 后序遍历递归
    bool PostR() {}
#endif
};
// @leet end

int main() {
    return 0;
}
