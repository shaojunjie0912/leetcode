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

// 二叉树前缀和 + 哈希表

// 二叉树前缀和: 从根节点开始的路径元素和 (从根出发, 那就前序遍历递归)

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
    int pathSum(TreeNode* root, int targetSum) {
        int ans{0};
        unordered_map<int64_t, int> cnt;
        cnt[0] = 1;  // 对应 pre_sum[0] = 0 出现一次
        // 计算二叉树前缀和
        function<void(TreeNode*, int64_t)> dfs = [&](TreeNode* node, int64_t pre_sum) -> void {
            if (!node) {
                return;
            }
            pre_sum += node->val;  // 中
            if (cnt.contains(pre_sum - targetSum)) {
                ans += cnt[pre_sum - targetSum];
            }
            ++cnt[pre_sum];  // 无论是否 contains 都要 ++ 防止漏掉键值对

            dfs(node->left, pre_sum);   // 左
            dfs(node->right, pre_sum);  // 右

            --cnt[pre_sum];  // 恢复现场
        };
        dfs(root, 0);  // 隐含 pre_sum[0] = 0
        return ans;
    }
};
// @leet end
