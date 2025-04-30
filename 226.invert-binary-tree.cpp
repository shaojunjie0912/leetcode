#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
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

// 递归
// 写法一: (自底向上, 递归返回值有用)
//  - 递归翻转左子树
//  - 递归翻转右子树
//  - 翻转 root 的 left 和 right (修改指向)
//  - 返回 root

// 写法二: (自顶向下, 递归返回值没用)
//  - 交换 root 的 left 和 right (物理交换, swap 指针)
//  - 递归翻转左子树
//  - 递归翻转右子树
//  - 返回 root

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        auto left{invertTree(root->left)};  // 返回值还是有用的
        auto right{invertTree(root->right)};
        root->left = right;
        root->right = left;
        return root;
    }
#else
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        // 物理交换 (这里用 swap 交换了指针值)
        std::swap(root->left, root->right);
        invertTree(root->left);  // 返回值已经不重要了
        invertTree(root->right);
        return root;
    }
#endif
};
// @leet end
