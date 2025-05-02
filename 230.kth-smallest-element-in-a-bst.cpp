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

// 中序遍历
// 法一: 简单, 记录答案
// 法二: 不记录答案并提前返回

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
    // 遍历所有, 用外部变量存储结果
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) -> void {
            if (!node) {
                return;
            }
            dfs(node->left);
            if (--k == 0) {  // 访问一个 k 就减一
                ans = node->val;
            }
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
#else
    // 提前返回
    int kthSmallest(TreeNode* root, int k) {
        // NOTE: 坑: 写在内部的 lambda 的 & 会捕获到 root, 可能写错 node root
        // 还是写明按引用捕获 &dfs, &k 为好
        function<int(TreeNode*)> dfs = [&dfs, &k](TreeNode* node) -> int {
            if (!node) {
                return -1;  // 空节点返回 -1, 也代表没有找到
            }
            // 左 (答案在左子树)
            if (int left_res = dfs(node->left); left_res != -1) {
                // 如果不等于 -1 说明找到答案了
                return left_res;
            }
            // 中 (答案在中间这个节点)
            if (--k == 0) {
                return node->val;
            }
            // 右 (答案在右子树)
            return dfs(node->right);
        };
        return dfs(root);
    }

#endif
};
// @leet end
