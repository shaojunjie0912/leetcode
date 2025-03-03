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
public:
    // NOTE: !!根节点!!->!!叶节点!!
    // 递归
    // 全局 vector: 存放路径(元素在递归结束要去除)
    // 大 vector: 存放满足题意的路径
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> path;
        R(res, path, targetSum, 0, root);
        return res;
    }

    void R(vector<vector<int>>& res, vector<int>& path, int target, int sum, TreeNode* curr) {
        // HACK: 形参 sum: 当前节点之前的总和
        // 递归终止条件: 叶节点
        // 感觉递归的奥义??在终止条件中处理?
        if (!curr->left && !curr->right) {
            // HACK: 满足target才操作, 不满足当然不用先入再出, 浪费
            if (curr->val + sum == target) {
                path.push_back(curr->val);  // 当前值加入小数组
                res.push_back(path);        // 移动到大数组
                path.pop_back();            // 去除当前值
            }
        }
        // ========= 非叶节点 ==========
        else {
            // NOTE: 先加入当前值
            path.push_back(curr->val);
            // 左递归(非空)
            if (curr->left) {
                R(res, path, target, sum + curr->val, curr->left);
            }
            // 右递归(非空)
            if (curr->right) {
                R(res, path, target, sum + curr->val, curr->right);
            }
            // NOTE: 再删除当前值
            path.pop_back();
        }
    }
};
// @leet end

int main() {
    return 0;
}
