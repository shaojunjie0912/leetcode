#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 搜索二叉树(每个节点): ..left.. < root < ..right..

// 前/中/后序递归
// 用int64_t, 防止INT_MIN, INT_MAX, 就 = 了而不是 <

// 1. 前序遍历递归:
// 传入节点同时, 传入开区间范围 (l_bound, r_bound) 即 l_bound < x < r_bound
// 开区间因为是搜索二叉树严格 <

// 2. 中序遍历递归:
// 中序遍历的结果就是一个严格递增数组
// 要把前一个值用外部变量记录下来

// 3. 后序遍历递归:
// 从下往上传范围,
// 需要先遍历左右子树(获得左右子树最大值最小值), 再跟当前节点比较

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
        // return PreDfs(root, INT64_MIN, INT64_MAX);
        // return InDfs(root);
        return PostDfs(root).first != INT64_MIN;  // 不等于 INT64_MIN 才是对的
    }

private:
    // 前序遍历递归
    // 传入节点同时, 传入开区间范围 (l_bound, r_bound) 即 l_bound < x < r_bound
    // 开区间因为是搜索二叉树严格 <
    bool PreDfs(TreeNode* root, int64_t l_bound, int64_t r_bound) {
        if (!root) {  // 边界条件
            return true;
        }
        int64_t x = root->val;
        // 前序:
        // 1. 当前节点满足条件
        // 2. 左子树满足条件(更新右边界为 x)
        // 3. 右子树满足条件(更新左边界为 x)
        return l_bound < x && x < r_bound && PreDfs(root->left, l_bound, x) &&
               PreDfs(root->right, x, r_bound);
    }

    // 中序遍历递归
    // 中序遍历的结果就是一个严格递增数组
    // 要把前一个值用外部变量记录下来
    int64_t pre = INT64_MIN;  // int64_t !
    bool InDfs(TreeNode* root) {
        if (!root) {  // 边界条件
            return true;
        }
        // 左
        if (!InDfs(root->left)) {
            return false;
        }

        // 中
        if (root->val <= pre) {
            return false;
        }
        pre = root->val;

        // 右
        if (!InDfs(root->right)) {
            return false;
        }

        return true;
    }

    // 后序遍历递归
    // 从下往上传范围, 需要先遍历左右子树(获得左右子树最大值最小值), 再跟当前节点比较
    pair<int64_t, int64_t> PostDfs(TreeNode* root) {
        if (!root) {  // 边界条件, 去除空节点影响
            return {INT64_MAX, INT64_MIN};
        }
        auto [l_min, l_max] = PostDfs(root->left);   // 左子树 (min, max)
        auto [r_min, r_max] = PostDfs(root->right);  // 右子树 (min, max)

        // 如果不满足条件就直接提前返回一个肯定打破条件的范围
        // 注意这里的条件 >= 因为搜索二叉树严格
        if (l_max >= root->val || root->val >= r_min) {
            return {INT64_MIN, INT64_MAX};
        }

        // 对于空节点, l_min 为 INT64_MAX, 如果直接往上传, 则就不对了
        // 应该跟当前节点值比较, r_max 同理
        return {min((int64_t)root->val, l_min), max((int64_t)root->val, r_max)};
    }
};
// @leet end

int main() { return 0; }
