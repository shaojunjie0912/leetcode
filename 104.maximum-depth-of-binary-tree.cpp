#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 递归两种写法
// 自底向上
// 自顶向下

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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
#else
    // 自顶向下 (dfs)
    int maxDepth(TreeNode* root) {
        int ans{0};
        auto dfs = [&](auto&& self, TreeNode* root, int depth) -> void {
            if (!root) {
                return;
            }
            ++depth;  // 每递归一层, 深度 + 1
            ans = max(ans, depth);
            self(self, root->left, depth);
            self(self, root->right, depth);
        };
        dfs(dfs, root, 0);
        return ans;
    }
#endif
};
// @leet end

int main() { return 0; }
