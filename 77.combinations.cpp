#include <bits/stdc++.h>
#include <fmt/base.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"
// #include "utils/debug.hpp"

using namespace std;
using namespace fmt;

// 组合型回溯

// @leet start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](auto&& self, int i) {
            // 剪枝:
            // i 反过来从小到大枚举: [n, n-1, n-2, ..., 1], 剪枝判断 i < d 简单一些
            // 一共要选 k 个数, 如果当前 i < k - path.size(), 那么后面肯定凑不齐 k 个数, 直接丢掉
            int d = k - path.size();
            if (i < d) {
                return;
            }
            // 边界条件
            if (path.size() == k) {
                ans.push_back(path);
                return;
            }
            for (int j = i; j >= 1; --j) {
                path.push_back(j);
                self(self, j - 1);
                path.pop_back();  // 恢复现场
            }
        };
        dfs(dfs, n);  // 从 n 开始倒着枚举
        return ans;
    }
};
// @leet end

int main() {
    // 范围 [1, n] 的 k 个数的组合
    int n = 4, k = 2;
    Solution s;
    auto res{s.combine(n, k)};
    for (auto& vec : res) {
        print("{} ", vec);
    }
    print("\n");
    return 0;
}
