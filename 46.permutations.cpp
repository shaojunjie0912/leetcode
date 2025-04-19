#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 排列型回溯

// @leet start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n);
        vector<int> on_path(n);
        auto dfs = [&](auto&& self, int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!on_path[j]) {
                    path[i] = nums[j];
                    on_path[j] = 1;  // 已选上
                    self(self, i + 1);
                    on_path[j] = 0;  // 恢复现场
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
// @leet end

int main() { return 0; }
