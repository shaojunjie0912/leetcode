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

// 思考: 树的直径和最大深度(最长链)的联系

// 直径会在某个节点「拐弯」, 所以枚举每个节点, 更新直径
// 在当前节点「拐弯」的直径长度
//                ↓
// 2 + 左子树的最长链 + 右子树的最长链

// 空节点的链长: -1
// 叶节点的链长: 0

// 以当前节点为根的子树的最长链
//                ↓
// 1 + max(左子树的最长链, 右子树的最长链)

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans{0};
        std::function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) {
                return -1;  // 空节点链长: -1
            }
            int l_depth{dfs(node->left)};   // 左子树最长链(最大深度)
            int r_depth{dfs(node->right)};  // 右子树最长链(最大深度)

            // 在当前节点「拐弯」的直径长度
            //                ↓
            // 2 + 左子树的最长链 + 右子树的最长链
            ans = max(ans, 2 + l_depth + r_depth);

            // 以当前节点为根的树的最长链
            //                ↓
            // 1 + max(左子树的最长链, 右子树的最长链)
            return 1 + max(l_depth, r_depth);
        };
        dfs(root);  // 递归入口
        return ans;
    }
};
// @leet end
