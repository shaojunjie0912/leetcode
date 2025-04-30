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

// 两棵相同的树 p 和 q 翻版!!!
// 但是!
// p 的<左>子树与 q 的<右>子树相同
// p 的<右>子树与 q 的<左>子树相同

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
    bool isSymmetric(TreeNode* root) { return IsSameTree(root->left, root->right); }

private:
    bool IsSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }
        return (p->val == q->val) && IsSameTree(p->left, q->right) && IsSameTree(p->right, q->left);
    }
};
// @leet end
