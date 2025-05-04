#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 思考递归:

// 原问题:
// 前序遍历 preorder[0] 是根
//           ↓
// 中序遍历 inorder 中根左边: 左子树及其大小, 根右边: 右子树及其大小
//           ↓
// 前序遍历 preorder 左子树, 右子树
//           ↓
// 子问题:
// 左右子树的前序遍历和中序遍历

// 优化:
// 1. 哈希表记录 inorder 每个元素对应的下标, 这样就能 O(1) 找到 preorder[0]
// 2. 递归参数改为子数组下标区间 (左闭右闭), 避免复制

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
#if 1
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> index_map;
        for (int i = 0; i < n; ++i) {
            index_map[inorder[i]] = i;  // 记录 inorder 元素和对应索引
        }
        // pre: [pre_l, pre_r)
        // in: [in_l, in_r)
        function<TreeNode*(int, int, int, int)> dfs = [&](int pre_l, int pre_r, int in_l,
                                                          int in_r) -> TreeNode* {
            // NOTE: 边界条件: 左闭右开区间, 跟 vector 区间差不多?
            if (pre_l == pre_r) {
                return nullptr;
            }
            // pre_l: 前序遍历结果数组第一个元素
            int left_size = index_map[preorder[pre_l]] - in_l;
            auto left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            auto right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
            return new TreeNode{preorder[pre_l], left, right};
        };
        return dfs(0, n, 0, n);
    }
#else
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {  // NOTE: 边界条件: 空节点
            return nullptr;
        }
        // 左子树大小
        auto left_size{ranges::find(inorder, preorder[0]) - inorder.begin()};

        // 左右子树前序遍历结果数组
        vector<int> left_preorder{preorder.begin() + 1, preorder.begin() + 1 + left_size};
        vector<int> right_preorder{preorder.begin() + 1 + left_size, preorder.end()};

        // 左右子树中序遍历结果数组
        vector<int> left_inorder{inorder.begin(), inorder.begin() + left_size};
        vector<int> right_inorder{inorder.begin() + left_size + 1, inorder.end()};

        auto left{buildTree(left_preorder, left_inorder)};     // 递归左子树
        auto right{buildTree(right_preorder, right_inorder)};  // 递归右子树

        return new TreeNode{preorder[0], left, right};
    }
#endif
};
// @leet end

int main() { return 0; }
