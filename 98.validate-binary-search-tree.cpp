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
        // return InR(root);
        return PostR(root).first != INT64_MIN;
    }

private:
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
        return left < x && x < right && PreR(root->left, left, x) && PreR(root->right, x, right);
    }

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

    // 后序遍历递归
    // 从下往上传范围, 需要先遍历左右子树(获得左右子树最大值最小值), 再跟当前节点比较
    pair<int64_t, int64_t> PostR(TreeNode* root) {
        if (!root) {
            return {INT64_MAX, INT64_MIN};  // NOTE: 去除空节点影响
        }
        // 先获取左子树最大最小值
        auto [l_min, l_max] = PostR(root->left);
        // 再获取右子树最大最小值
        auto [r_min, r_max] = PostR(root->right);
        if (l_max >= root->val || root->val >= r_min) {  // HACK: 条件
            // 不满足条件直接返回一个肯定打破条件的范围
            return {INT64_MIN, INT64_MAX};
        }
        // 满足条件就再把范围网上传
        // HACK: 最小值和最大值都要!
        // HACK: 需要跟当前节点值比较, 因为如果左子树是空树
        // 那么最小值应该是当前节点值, 否则就变成 INT64_MAX 了
        return {min((int64_t)root->val, l_min), max((int64_t)root->val, r_max)};
    }
};
// @leet end

int main() {
    return 0;
}
