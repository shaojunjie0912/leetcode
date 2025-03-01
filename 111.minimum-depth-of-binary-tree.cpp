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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
#if 1
    // NOTE: 解法1: BFS(迭代) 左神是dfs但是bfs时间复杂度更好
    // 因为 bfs 层序遍历到某个叶节点提前返回, 不会始终遍历所有节点
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int min_depth{0};
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            int size = node_queue.size();
            ++min_depth;  // 每一层使得最小深度 ++
            while (size--) {
                auto node{node_queue.front()};
                node_queue.pop();
                if (node->left) {
                    node_queue.push(node->left);
                }
                if (node->right) {
                    node_queue.push(node->right);
                }
                // HACK: 叶节点直接返回
                if (!node->left && !node->right) {
                    return min_depth;
                }
            }
        }
        return min_depth;
    }
#else
    // NOTE: 解法2: DFS(递归)
    // 1. 递归退出条件: 到叶节点
    // 2. 防止空树提前返回 0 影响 std::min 判断
    //     - 左树非空才调用递归
    //     - 右树非空才调用递归
    // 3. 初始化 l/r_min 为最大值
    int minDepth(TreeNode* root) {
        // 空树
        if (!root) {
            return 0;
        }
        // 叶节点(返回 1)
        if (!root->left && !root->right) {
            return 1;
        }
        int l_min_depth{INT_MAX};
        int r_min_depth{INT_MAX};

        if (root->left) {  // HACK: 不为空(没有<!符号>)
            // NOTE: 这里别犹豫, 没 + 1, 本来就是子树深度
            l_min_depth = minDepth(root->left);
        }
        if (root->right) {  // HACK: 不为空(没有<!符号>)
            // NOTE: 这里别犹豫, 没 + 1, 本来就是子树深度
            r_min_depth = minDepth(root->right);
        }
        // HACK: 最后要加 1
        return std::min(l_min_depth, r_min_depth) + 1;
    }
#endif
};
// @leet end

int main() {
    return 0;
}
