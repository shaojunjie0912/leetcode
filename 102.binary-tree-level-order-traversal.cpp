#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 队列

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> queue;
        vector<vector<int>> res;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();  // NOTE: 提前获取 size
            vector<int> in_res;
            while (size--) {
                auto top{queue.front()};
                in_res.push_back(top->val);
                queue.pop();
                if (top->left) {
                    queue.push(top->left);
                }
                if (top->right) {
                    queue.push(top->right);
                }
            }
            res.push_back(in_res);
        }
        return res;
    }
};
// @leet end

int main() { return 0; }
