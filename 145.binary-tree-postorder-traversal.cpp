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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        PostOrder(root, res);
        return res;
    }

    void PostOrder(TreeNode* root, vector<int>& nums) {
        if (!root) {
            return;
        }
        PostOrder(root->left, nums);
        PostOrder(root->right, nums);
        nums.push_back(root->val);
    }
};
// @leet end

int main() {
    return 0;
}
