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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < n; ++i) {
            inorder_map[inorder[i]] = i;  // 记录 inorder 元素和对应索引
        }
        // [pre_l, pre_r] [in_l, in_r]
        // 理解为数组 pre 和 in 的左右边界, 而不是左右子树的 pre 和 in
        function<TreeNode*(int, int, int, int)> build = [&](int pre_l, int pre_r, int in_l,
                                                            int in_r) -> TreeNode* {
            if (pre_l > pre_r) {
                return nullptr;
            }
            int left_size = inorder_map[preorder[pre_l]] - in_l;  // NOTE: 要减去 in_l
            auto left_node = build(pre_l + 1, pre_l + left_size, in_l, in_l + left_size - 1);
            auto right_node = build(pre_l + left_size + 1, pre_r, in_l + left_size + 1, in_r);
            return new TreeNode{preorder[pre_l], left_node, right_node};
        };
        return build(0, n - 1, 0, n - 1);
    }
};
// @leet end

int main() { return 0; }
