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
#if 0
    // 递归
    vector<int> inorderTraversal(TreeNode* root) {
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
        nums.push_back(root->val);
        PostOrder(root->right, nums);
    }
#else
    // 迭代
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> st;
        auto curr{root};
        // NOTE: 当 curr 非空或栈非空
        while (curr || !st.empty()) {
            // 将 curr 压入栈中，然后更新 curr 为其左子节点
            // 直到抵达最左边
            // NOTE: 其实这里就是先压根节点, 再压左子节点, 出栈顺序相反
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            // curr 为空，则左子树已处理完
            // 弹出栈顶元素 (!当前子树的根!相对上一级是左节点), 访问
            auto node = st.top();
            st.pop();
            ans.push_back(node->val);

            // curr 更新为右子树
            curr = node->right;
        }
        return ans;
    }

#endif
};
// @leet end

int main() { return 0; }
