#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 区别于固定个数 k 的组合型回溯
// 1. 这里没有 k 的个数限制, 只有目标和限制
// 2. 这里的数组不一定有序, 所以从正序遍历, 但其实你排完序后就可以倒序了

// NOTE: 同一个数字可以无限制重复被选取

// @leet start
class Solution {
public:
#if 0
    // 输入角度: 选/不选
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();

        // 优化: 从小到大排序
        ranges::sort(candidates);

        function<void(int, int)> dfs = [&](int i, int t) -> void {
            // 这其实不是边界条件, 这是找到答案了提前 return
            if (t == 0) {
                ans.push_back(path);
                return;
            }

            // 这是没找到答案或 t < 0 不能再选了无奈返回的边界条件
            // 优化一下: 对于排序后的数组 t < candidates[i] 就可以退出了
            if (i == n || t < candidates[i]) {
                return;
            }

            // 不选
            dfs(i + 1, t);

            // 选
            path.push_back(candidates[i]);
            dfs(i, t - candidates[i]);  // 可重复选取, 还是 i
            path.pop_back();            // 恢复现场
        };

        dfs(0, target);
        return ans;
    }
#else
    // 答案角度: 枚举选哪个
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();

        ranges::sort(candidates);

        // 枚举 [i, n-1]
        function<void(int, int)> dfs = [&](int i, int t) -> void {
            if (t == 0) {
                ans.push_back(path);
                return;
            }

            if (i == n || t < candidates[i]) {
                return;
            }

            // 用 j 遍历 [i, n-1]
            for (int j = i; j < n; ++j) {
                path.push_back(candidates[j]);  //
                dfs(j, t - candidates[j]);      // NOTE: 这里是 j !!!
                path.pop_back();                // 恢复现场
            }
        };

        dfs(0, target);

        return ans;
    }
#endif
};
// @leet end

int main() { return 0; }
