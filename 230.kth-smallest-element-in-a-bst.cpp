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
// 写一个 function dfs, 按引用捕获外部变量
// 参数是 TreeNode*
// 返回值是 int, -1 代表没有找到
// 重点在对于当前访问根节点的处理: --k, 不写一个 dfs 不好搞

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
    int kthSmallest(TreeNode* root, int k) {
        // NOTE: 坑: 写在内部的 lambda 的 & 会捕获到 root, 可能写错 node root
        // 还是写明按引用捕获 &InDfs, &k 为好
        function<int(TreeNode*)> InDfs = [&InDfs, &k](TreeNode* node) -> int {
            if (!node) {
                return -1;  // 空节点返回 -1, 也代表没有找到
            }
            // 左 (答案在左子树)
            if (int left_res = InDfs(node->left); left_res != -1) {
                // 如果不等于 -1 说明找到答案了
                return left_res;
            }
            // 中 (答案在中间这个节点)
            if (--k == 0) {
                return node->val;
            }
            // 右 (答案在右子树)
            return InDfs(node->right);
        };
        return InDfs(root);
    }
};
// @leet end
