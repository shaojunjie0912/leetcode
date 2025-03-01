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
    // NOTE: 最大深度直接递归, 别忘了子树深度 + 1
    int maxDepth(TreeNode* root) {
        return root ? std::max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};
// @leet end

int main() {
    return 0;
}
