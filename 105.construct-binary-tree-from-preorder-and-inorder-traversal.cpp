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
    // 根据先序+中序特点
    // 先序[l1, ..., r1] l1 位置肯定是根节点
    // 中序[l2, ...k..., r2] l2 ~ k-1 范围肯定是左数的节点
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // HACK: 优化: 使用哈希表提前记录inorder所有节点索引, 避免find每次查找
        unordered_map<int, int> in_map;
        for (int i{0}; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }
        return PreInOrderBuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1,
                               in_map);
    }

    // 1. 先有根节点
    // 2. 构建左子树
    // 3. 构建右子树
    TreeNode* PreInOrderBuild(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2,
                              unordered_map<int, int>& in_map) {
        // HACK: 终止条件, 当[l1, r1]中 l1 == r1 时 即只有一个节点
        if (l1 > r1) {
            return nullptr;
        }
        auto root{new TreeNode{pre[l1]}};
        // 根节点在中序遍历数组的位置(根据它确定左右树范围)
        int k = in_map[pre[l1]];
        int left_size = k - l2;
        // NOTE: 左右子树范围(下标换算!!)
        root->left = PreInOrderBuild(pre, l1 + 1, l1 + left_size, in, l2, k - 1, in_map);
        root->right =
            PreInOrderBuild(pre, l1 + left_size + 1, r1, in, k + 1, r2, in_map);  // 左树右边界+1
        return root;
    }
};
// @leet end

int main() {
    return 0;
}
