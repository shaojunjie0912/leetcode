#include <fmt/base.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <functional>
#include <vector>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;
using namespace fmt;

// 组合型回溯
// 相比于普通子集型回溯加了剪枝

// @leet start
class Solution {
public:
#if 1
    // 结果角度: 枚举选哪一个
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int)> dfs = [&](int i) {
            // 剪枝:
            // i 反过来从大到小枚举
            // [1, 2, 3, ..., n]
            //              ← i
            // 一共要选 k 个数, 如果 d = k - path.size() = 0 说明选好了
            // NOTE: 这里边界不用 i 而是提前根据 path.size() 判断退出
            int d = k - path.size();
            if (d == 0) {
                ans.push_back(path);
                return;
            }

            // 用 j 倒序遍历 [0, i]
            for (int j = i; j >= 1; --j) {
                path.push_back(j);  //
                dfs(j - 1);         // 倒序遍历剩下的 [0, j-1]
                path.pop_back();    // 恢复现场
            }
        };

        dfs(n);  // NOTE: 递归入口是 n
        return ans;
    }
#else
    // 输入角度: 选/不选
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs = [&](int i) -> void {
            // 剪枝
            int d = k - path.size();
            if (d == 0) {  // d = 0 说明选好了
                ans.push_back(path);
                return;
            }

            // 不选
            // NOTE: i > d 才能不选, 不然本来就不够, 咋能不选?
            if (i > d) {
                dfs(i - 1);
            }

            // 选
            path.push_back(i);
            dfs(i - 1);
            path.pop_back();  // 恢复现场
        };

        dfs(n);
        return ans;
    }
#endif
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
