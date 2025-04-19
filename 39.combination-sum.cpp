#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 子集型回溯
// NOTE: 同一个数字可以无限制重复被选取

// @leet start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        // left 是剩下选的数的和
        auto dfs = [&](auto&& self, int i, int left) {
            // 保存结果
            if (left == 0) {
                ans.push_back(path);
                return;
            }
            // 边界条件?
            if (i == candidates.size() || left < 0) {
                return;
            }
            // 不选
            self(self, i + 1, left);
            // 选
            path.push_back(candidates[i]);
            self(self, i, left - candidates[i]);  // NOTE: 还是 i 因为可以重复选
            path.pop_back();                      // 恢复现场
        };
        dfs(dfs, 0, target);  // 递归入口
        return ans;
    }
};
// @leet end

int main() { return 0; }
