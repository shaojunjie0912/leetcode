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

// 深度: 从根节点到该节点所经历的边的条数
// 高度: 从该节点到其最远叶子节点的最长路径上的边的条数

// 思考: 树的直径和高度 (即最长链) 之间的联系

// 直径 = 2 + 左子树高度 + 右子树高度

// 空节点的高度: -1
// 叶节点的高度: 0

// dfs 输入参数: 当前节点 node, 输出参数: 高度
// 当前节点高度 = 1 + max(左子树高度, 右子树高度)

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

        // dfs 返回的是节点 node 的高度
        std::function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) {
                return -1;  // 空节点高度: -1
            }

            int l_depth{dfs(node->left)};  // 左子树高度
            int r_len{dfs(node->right)};   // 右子树高度

            ans = max(ans, 2 + l_depth + r_len);  // 直径 = 2 + 左子树高度 + 右子树高度

            return 1 + max(l_depth, r_len);  // 当前节点高度 = 1 + max(左子树高度, 右子树高度)
        };

        dfs(root);
        return ans;
    }
};
// @leet end
