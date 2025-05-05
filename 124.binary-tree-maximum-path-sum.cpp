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

// 同: 求直径, 核心由最大链长 -> 最大链和

// 最大路径和 = 当前节点值 + 左子树最大链和 + 右子树最大链和

// NOTE: 计算最大链和时, 如果是负数则返回 0, 跟直径不同, 路径上我可以不选负数叶子节点
// 链和 != 直径和, 因为直径是最长链, 而这里路径只是链
// 最大链和 = max(0, 当前节点 + max(左子树最大链和, 右子树最大链和))

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
    int maxPathSum(TreeNode* root) {
        int ans{INT_MIN};  // 思考: 求最大时有负数, 别干扰
        // dfs 返回节点 node 的最大链和 (如果是负数则返回 0)
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) {
                return 0;  // 思考: 求最大时有负数, 别干扰
            }
            int left = dfs(node->left);                   // 左子树最大链和
            int right = dfs(node->right);                 // 右子树最大链和
            ans = max(ans, node->val + left + right);     // 更新最大路径和
            return max(0, node->val + max(left, right));  // 返回当前节点最大链和(不要负数)
        };
        dfs(root);
        return ans;
    }
};
// @leet end
