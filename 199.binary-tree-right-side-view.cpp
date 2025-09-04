#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
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

// 递归: 当某个深度首次遇到(即数组目前大小=当前节点深度)时, 就是右视图的节点

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
    // 递归
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*, int)> dfs = [&dfs, &ans](TreeNode* node, int depth) -> void {
            if (!node) {
                return;
            }
            if (depth == ans.size()) {  // NOTE: 深度首次遇到
                ans.push_back(node->val);
            }
            dfs(node->right, depth + 1);  // NOTE: 先递归右子树!!!
            dfs(node->left, depth + 1);
        };
        dfs(root, 0);
        return ans;
    }
};
// @leet end
