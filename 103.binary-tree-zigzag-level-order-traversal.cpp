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
    // NOTE: 优化: 双端队列 -> 数组
    // HACK: 最关键就是借助容器先按题目要求顺序取元素,
    // 而不是陷入到bfs中

    // 1. 先按左->右/右->左顺序收集(HACK: 双端队列)
    // 2. 再 bfs
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        deque<TreeNode*> deq;
        deq.push_front(root);
        // HACK: iter=begin 从 deque 的 front -> back 读元素
        // 但是层序遍历入队是左 -> 右, 入队后右在 front, 左在 back
        // 所以 iter=begin 相当于右 -> 左读元素
        bool reverse{false};  // 不翻转, 二叉树左 -> 右
        while (!deq.empty()) {
            vector<int> in_res;
            if (reverse) {
                for (auto iter{deq.begin()}; iter != deq.end(); ++iter) {
                    in_res.push_back((*iter)->val);
                }
            } else {
                for (auto iter{deq.rbegin()}; iter != deq.rend(); ++iter) {
                    in_res.push_back((*iter)->val);
                }
            }
            res.push_back(in_res);
            int size = deq.size();
            while (size--) {
                auto top{deq.back()};
                deq.pop_back();
                if (top->left) {
                    deq.push_front(top->left);
                }
                if (top->right) {
                    deq.push_front(top->right);
                }
            }
            reverse = !reverse;
        }
        return res;
    }
};
// @leet end

int main() {
    return 0;
}
