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

class Codec {
public:
    // NOTE: 前序遍历 + '#' 标记空节点 + 空格 ' ' 分隔数字
    string serialize(TreeNode* root) {
        ostringstream oss;  // NOTE: 字符串流!!!
        function<void(TreeNode*)> dfs = [&](TreeNode* node) -> void {
            if (!node) {
                // NOTE: 空节点用 '#' 表示, 分隔符是空格 ' '
                oss << "# ";
                return;
            }
            // NOTE: oss 直接 << 不需要数字转字符串
            oss << node->val << " ";  // 根 NOTE: ' ' 空格分隔符
            dfs(node->left);          // 左
            dfs(node->right);         // 右
        };
        dfs(root);
        return oss.str();
    }

    // NOTE: istringstream 自动跳过空格
    TreeNode* deserialize(string data) {
        istringstream iss{data};  // 用 string 初始化 istringstream
        string val;
        function<TreeNode*()> dfs = [&]() -> TreeNode* {
            iss >> val;        // 从流中读取一个值
            if (val == "#") {  // '#' 空节点
                return nullptr;
            }
            // 根 NOTE: stoi 字符串转整数
            auto node{new TreeNode{std::stoi(val)}};
            node->left = dfs();   // 左 NOTE: 不需要传参, 遇到 '#' 就退出
            node->right = dfs();  // 右 NOTE: 不需要传参, 遇到 '#' 就退出
            return node;
        };
        return dfs();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @leet end

int main() { return 0; }
