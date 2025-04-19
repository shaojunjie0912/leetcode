#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 组合型回溯
// [9, 8, 7, ..., 1]
// 还是在范围内选 k 个数, 但是这次多了一个和为 n 的条件

// @leet start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        // NOTE: 参数多了一个 t(target 还需要选的和, 辅助剪枝)
        auto dfs = [&](auto&& self, int i, int t) {
            // 剪枝
            // 比之前多了几种剪枝情况
            // 1. 设还需要选和为 t 的数, 选一个数就减去, 当 t < 0 时, 丢弃
            // 2. 剩余 d 个数字即使全部选择最大, 和也 < t, 丢弃
            //    例如剩下 d 个数字, t > i + i-1 + ... + i-d+1
            int d = k - path.size();
            if (t < 0 || t > (i + i - d + 1) * d / 2 || i < d) {
                return;
            }

            // 记录答案
            // 如果 path.size() = k, 那么上面 d = 0, 那么 t = 0
            // 因此不需要额外判断了
            if (path.size() == k /* && t == 0 */) {
                ans.push_back(path);
            }
            for (int j = i; j >= 1; --j) {
                path.push_back(j);
                self(self, j - 1, t - j);  // 剩下的和减去当前值 j
                path.pop_back();
            }
        };
        dfs(dfs, 9, n);
        return ans;
    }
};
// @leet end

int main() { return 0; }
