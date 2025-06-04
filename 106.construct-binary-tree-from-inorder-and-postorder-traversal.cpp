#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; ++i) {
            umap[inorder[i]] = i;  // 记录 inorder 元素和对应索引
        }
        function<TreeNode*(int, int, int, int)> build = [&](int post_l, int post_r, int in_l,
                                                            int in_r) -> TreeNode* {
            if (post_l > post_r) {
                return nullptr;
            }
            int root_val = postorder[post_r];
            int left_size = umap[root_val] - in_l;
            auto left_node = build(post_l, post_l + left_size - 1, in_l, in_l + left_size - 1);
            auto right_node = build(post_l + left_size, post_r - 1, in_l + left_size + 1, in_r);
            return new TreeNode{root_val, left_node, right_node};
        };
        return build(0, n - 1, 0, n - 1);
    }
};
// @leet end
