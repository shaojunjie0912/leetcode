#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 两种情况冲突: 空树 false, 空节点
        // 解决方案: 空树直接 false + 到叶节点就返回
        // 根 -> 叶
        if (!root) {
            return false;
        }
        int new_target = targetSum - root->val;  // 剩下的目标值要减去当前节点值
        if (!root->left && !root->right) {       // 叶节点
            return new_target == 0;
        }
        return hasPathSum(root->left, new_target) || hasPathSum(root->right, new_target);
    }
};
// @leet end
