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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // NOTE: 搜索二叉树!!!
    // 搜索二叉树(每个root节点): ..left.. < root < ..right..
    // 没有重复值

    // HACK: 遍历的当前节点四种情况
    // 如果包含在一棵树:
    // 1. 先遇到p, 则返回p; 先遇到q, 则返回q
    // 2. root 值在 min(p,q) 左侧, 则往右移动
    // 3. root 值在 max(p,q) 右侧, 则往左移动

    // 如果分叉在两棵树:
    // 4. root 值在 p, q 之间, 返回 root
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // NOTE: 这里的循环以及条件判断写法很简洁
        // HACK: !!这里通过值而不是指针判断不相等!!
        // 遇到 p/q 则循环条件不满足而退出
        while ((root->val != p->val) && (root->val != q->val)) {
            // 在 p,q 值中间
            if ((min(p->val, q->val) < root->val) && (root->val < max(p->val, q->val))) {
                break;  // 也是返回 root
            }
            // 否则 root 向左/右移动
            root = (root->val < (min(p->val, q->val)) ? root->right : root->left);
        }
        return root;
    }
};
// @leet end

int main() {
    return 0;
}
