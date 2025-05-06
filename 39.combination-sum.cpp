#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 区别于固定个数 k 的组合型回溯
// 1. 这里没有 k 的个数限制, 只有目标和限制
// 2. 这里的数组不一定有序, 所以从正序遍历

// NOTE: 同一个数字可以无限制重复被选取

// @leet start
class Solution {
public:
#if 1
    // 输入角度: 选/不选
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        function<void(int, int)> dfs = [&](int i, int t) -> void {
            // 这是没找到答案或 t < 0 不能再选了无奈返回的边界条件
            if (i == n || t < 0) {
                return;
            }

            // 这其实不是边界条件, 这是找到答案了提前 return
            if (t == 0) {
                ans.push_back(path);
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
#endif
};
// @leet end

int main() { return 0; }
