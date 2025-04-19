#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 子集型回溯
// 输入角度: 每个数 选/不选

// @leet start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;  // NOTE: 跟电话号码不一样, 没有初始大小
        int n = nums.size();
        auto dfs = [&](auto&& self, int i) {
            // 边界条件
            if (i == n) {
                ans.push_back(path);
                return;
            }
            // 非边界条件 (下标 >= i 构造子集)
            // 不选
            self(self, i + 1);
            // 选
            path.push_back(nums[i]);

            // 下标 >= i+1 构造子集
            self(self, i + 1);

            // NOTE: 恢复现场
            path.pop_back();
        };
        dfs(dfs, 0);
        return ans;
    }
};
// @leet end

int main() { return 0; }
