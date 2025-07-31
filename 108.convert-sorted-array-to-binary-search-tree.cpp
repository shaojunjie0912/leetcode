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

// 递归 (递归边界条件!!)
// 将 nums 一分为二: (因为有二分, 因此边界条件也跟区间开闭相关!)
// 根节点: nums[middle]
// 左边转为平衡搜索二叉树
// 右边转为平衡搜索二叉树

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> dfs = [&](int l, int r) -> TreeNode* {
            // NOTE: 边界条件!!! 因为我取的是 []
            if (l > r) {
                return nullptr;
            }
            int m = l + (r - l) / 2;
            // NOTE: 妙啊, new 一个节点
            return new TreeNode{nums[m], dfs(l, m - 1), dfs(m + 1, r)};
        };
        return dfs(0, nums.size() - 1);
    }
};
// @leet end
