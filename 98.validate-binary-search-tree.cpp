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
// NOTE: 搜索二叉树(每个节点): ..left.. < root < ..right..
#if 1
    // HACK: 测试用例存在 INT_MAX, 导致问题, 得用 LONG_LONG
    long long g_min{LONG_LONG_MAX};  // 全局变量-最小值
    long long g_max{LONG_LONG_MIN};  // 全局变量-最大值
    // 方法二: 递归
    // NOTE: 对于每一个节点:
    // 想得到左子树 l_min 和 l_max
    // 想得到右子树 r_min 和 r_max
    // 一旦某个过程结束, 更新 g_min,g_max
    // (包括 root + 左子树 min max + 右子树 min max)
    bool isValidBST(TreeNode* root) {
        // 递归终止条件(HACK: 空节点也要更新minmax)
        if (!root) {
            g_min = LONG_LONG_MAX;  // min->LONG_LONG_MAX 防止干扰
            g_max = LONG_LONG_MIN;  // max->LONG_LONG_MIN 防止干扰
            return true;
        }
        // 左子树是否是二叉搜索树(递归内部更新 g_min&g_max)
        bool l_is{isValidBST(root->left)};
        long long l_min = g_min;  // 记录左侧最小值
        long long l_max = g_max;  // 记录左侧最大值

        // 右子树是否是二叉搜索树(递归内部更新 g_min&g_max)
        bool r_is{isValidBST(root->right)};
        long long r_min = g_min;  // 记录右侧最小值
        long long r_max = g_max;  // 记录右侧最大值

        // HACK: 更新 g_min & g_max, 要算上当前 root 节点
        g_min = min(min(l_min, r_min), (long long)root->val);  // NOTE: 强转
        g_max = max(max(l_max, r_max), (long long)root->val);  // NOTE: 强转
        // NOTE: 符合条件 左子树是 + 右子树是 + 左max<中<右min
        return l_is && r_is && ((l_max < root->val) && (root->val < r_min));
    }
#else
    // 方法一: 中序遍历后一直升序(且没有相等)(NOTE: 不太行)
    // 按中序顺序一个一个, 要是当前值比前面一个小, 则 false
    // 非递归实现二叉树中序遍历(NOTE: 用!!栈!!)
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        return true;
    }
#endif
};
// @leet end

int main() {
    return 0;
}
