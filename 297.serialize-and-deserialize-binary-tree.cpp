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

class Codec {
public:
#if 1
    // NOTE: 处理逻辑有点变化, 根据序列化的要求
    // 不是每次处理一层，而是每次处理一个节点
    //   1
    // 2  3
    //
    // 1,2,3,#,#,#,#,
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        ostringstream oss;
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        oss << root->val << ",";  // HACK:
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size--) {
                auto node{nodes.front()};
                nodes.pop();
                // oss << node->val << ","; // NOTE: 这里没了
                if (node->left) {
                    nodes.push(node->left);
                    oss << node->left->val << ",";  // NOTE: 记得将左节点加入字符流
                } else {
                    oss << "#,";
                }
                if (node->right) {
                    nodes.push(node->right);
                    oss << node->right->val << ",";  // NOTE: 记得将右节点加入字符流
                } else {
                    oss << "#,";
                }
            }
        }
        return oss.str();
    }

    TreeNode* deserialize(string data) {
        // NOTE: 使用队列
        if (data.empty()) {
            return nullptr;
        }
        istringstream iss{data};
        string str_val;
        getline(iss, str_val, ',');
        // 获取根节点
        auto root{Generate(str_val)};

        auto curr{root};
        while (getline(iss, str_val, ',')) {
            if (str_val == "#") {
            }
        }
        return root;
    }

    TreeNode* Generate(string& str_val) {
        return str_val == "#" ? nullptr : new TreeNode{stoi(str_val)};
    }

#else
    // NOTE: 使用 istringstream & ostringstream 优化
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
        // NOTE: istringstream 是一个流, 内部维护了当前读取的位置
        getline(iss, val, ',');  // HACK: 根据 ',' 获取其中字符串
        if (val == "#") {
            return nullptr;  // "#" 代表空
        }
        TreeNode* root{new TreeNode{stoi(val)}};  // 中
        root->left = PreOrderDese(iss);           // 左
        root->right = PreOrderDese(iss);          // 左
        return root;
    }
#endif
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @leet end

int main() {
    return 0;
}
