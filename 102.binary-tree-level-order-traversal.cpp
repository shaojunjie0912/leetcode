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

static TreeNode* que[2001]{};

class Solution {
public:
#if 0
    // 每次处理一层, 本题推荐
    // 优化1: 自己用数组实现队列
    // 优化2: 修改逻辑: 1拿队列大小 2弹出+加左右
    // NOTE: 这里偷懒直接用std了, std 感觉没啥区别
    // 数组 nums[l, r) 一开始都是 0 循环条件: l < r
    // 入队: nums[r++] = node
    // 出队: nums[l++]
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        int l = 0;
        int r = 0;
        que[r++] = root;
        while (l < r) {
            int size = r - l;
            vector<int> in_res;
            while (size--) {
                auto top{que[l++]};
                in_res.push_back(top->val);
                if (top->left) {
                    que[r++] = top->left;
                }
                if (top->right) {
                    que[r++] = top->right;
                }
            }
            res.push_back(in_res);
        }
        return res;
    }

#elif 1
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> queue;
        vector<vector<int>> res;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> in_res;
            while (size--) {
                auto top{queue.front()};
                in_res.push_back(top->val);
                queue.pop();
                if (top->left) {
                    queue.push(top->left);
                }
                if (top->right) {
                    queue.push(top->right);
                }
            }
            res.push_back(in_res);
        }
        return res;
    }
#else
    // 普通 bfs 本题不推荐
    // NOTE: 二叉树层序遍历: BFS 宽度优先遍历
    // 使用队列, 入队 -> 出队 -> 有左加左, 有右加右
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> queue;
        vector<vector<int>> res;
        // 1. 每当一个节点进队列, 就记录层数
        // 2. 弹出节点, 查表看层数, 检查层数在不在结果数组中(索引)
        // 3. 有左加左, 有右加右
        unordered_map<TreeNode*, int> map;  // 层数记录表

        queue.push(root);
        map[root] = 0;
        while (!queue.empty()) {
            auto top{queue.front()};
            queue.pop();
            // 当前节点已经有对应层数组
            if (map[top] < res.size()) {  // HACK: 一开始写错把res写成queue了
                res[map[top]].push_back(top->val);
            }
            // 当前节点没有对应层数组
            else {
                res.push_back({top->val});
            }
            int layer = map[top];  // 获取当前节点的层数
            if (top->left) {
                queue.push(top->left);
                map[top->left] = layer + 1;
            }
            if (top->right) {
                queue.push(top->right);
                map[top->right] = layer + 1;
            }
        }
        return res;
    }
#endif
};
// @leet end

int main() {
    return 0;
}
