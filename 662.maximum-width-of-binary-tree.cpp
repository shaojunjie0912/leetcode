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
    // NOTE: BFS + 同时记录<树节点>和<编号>!!
    // 同步入队+同步出队
    // 头结点: 编号 1
    // 左孩子: 2 * i, 右节点: 2 * i +1
    int widthOfBinaryTree(TreeNode* root) {
        // if()
        std::queue<TreeNode*> node_queue;
        std::deque<unsigned long long> idx_deque;
        node_queue.push(root);
        idx_deque.push_back(1);  // NOTE: int 溢出了(答案相减, 但减数溢出)
        int max_width{0};        // NOTE: 本题求最大, 不是最后一层
        while (!node_queue.empty()) {
            int size = node_queue.size();
            // NOTE: 本题求最大, 不是最后一层
            if (int width = idx_deque.back() - idx_deque.front() + 1; width > max_width) {
                max_width = width;
            }
            while (size--) {
                // HACK: 改一下记忆: 统一一下 queue 和 deque
                // 右进 左出
                // queue: front ... back (push 从右进, pop 从左出)
                // deque: front ... back
                auto top_node{node_queue.front()};
                auto top_idx{idx_deque.front()};
                node_queue.pop();
                idx_deque.pop_front();
                if (top_node->left) {
                    node_queue.push(top_node->left);
                    idx_deque.push_back(2 * top_idx);
                }
                if (top_node->right) {
                    node_queue.push(top_node->right);
                    idx_deque.push_back(2 * top_idx + 1);
                }
            }
        }
        return max_width;
    }
};
// @leet end

int main() {
    return 0;
}
