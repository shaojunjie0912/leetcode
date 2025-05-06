#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 组合型回溯
// [1, 2, 3, ..., 9]
//              ← i
// 还是在范围内选 k 个数, 但是这次多了一个和为 n 的条件

// @leet start
class Solution {
public:
#if 1
    // 答案角度:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        // dfs 参数
        // i: 倒序枚举 [1, i]
        // t: 还需要选的和
        function<void(int, int)> dfs = [&](int i, int t) {
            // 剪枝
            // 1. 设还需要选和为 t 的数, 选一个数就减去, 当 t < 0 时, 丢弃
            // 2. 剩余 d 个数字即使全部选择最大, 和也小于 t, 丢弃
            //    例如剩下 d 个数字, t > i + (i - 1) + ... + (i - d + 1), 等差数列求和
            int d = k - path.size();
            if (t < 0 || t > (i + i - d + 1) * d / 2 || i < d) {
                return;
            }

            if (d == 0) {
                ans.push_back(path);
            }

            // 使用 j 遍历倒序枚举 [1, i]
            for (int j = i; j >= 1; --j) {
                path.push_back(j);  //
                dfs(j - 1, t - j);  // 枚举剩下的 [1, j - 1]
                path.pop_back();
            }
        };
        dfs(9, n);
        return ans;
    }
#else
    // 输入角度: 选/不选
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int t) -> void {
            int d = k - path.size();
            // 剪枝
            // 1. 设还需要选和为 t 的数, 选一个数就减去, 当 t < 0 时, 丢弃
            // 2. 剩余 d 个数字即使全部选择最大, 和也小于 t, 丢弃
            //    例如剩下 d 个数字, t > i + (i - 1) + ... + (i - d + 1), 等差数列求和
            if (t < 0 || t > (i + (i - d + 1)) * d / 2) {
                return;
            }
            // NOTE: 竟然通过剪枝来确保到下面的 d == 0 语句时, t 一定为 0
            if (d == 0) {
                // d == 0 时, 要跳过上面对于 t 的剪枝, 必须: 0<=t<=0, 则 t 一定为 0
                ans.push_back(path);
                return;
            }
            // 不选
            if (i > d) {
                dfs(i - 1, t);
            }
            // 选
            path.push_back(i);
            dfs(i - 1, t - i);
            path.pop_back();
        };

        dfs(9, n);
        return ans;
    }
#endif
};
// @leet end

int main() { return 0; }
