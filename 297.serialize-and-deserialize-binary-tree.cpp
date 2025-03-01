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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// NOTE: 只有先序、后序和层序遍历才有唯一序列化反序列化
// 中序存在相同树不同序列化结果的情况

// NOTE: 本题使用 istringstream & ostringstream 优化
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        PreOrderSe(root, oss);
        return oss.str();
    }

    // 先序遍历序列化辅助函数
    void PreOrderSe(TreeNode* root, ostringstream& oss) {
        if (!root) {
            oss << "#,";
            return;  // NOTE: 递归别忘记 return
        }
        oss << root->val << ",";
        PreOrderSe(root->left, oss);
        PreOrderSe(root->right, oss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss{data};
        return PreOrderDese(iss);
    }

    // 先序遍历反序列化辅助函数
    TreeNode* PreOrderDese(istringstream& iss) {
        string val;
        // NOTE: istringstream 本质上是一个流
        // 而流的内部维护了当前读取的位置
        getline(iss, val, ',');  // HACK: 根据 ',' 获取其中字符串
        if (val == "#") {
            return nullptr;  // "#" 代表空
        }
        TreeNode* root{new TreeNode{stoi(val)}};  // 中
        root->left = PreOrderDese(iss);           // 左
        root->right = PreOrderDese(iss);          // 左
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @leet end

int main() {
    return 0;
}
