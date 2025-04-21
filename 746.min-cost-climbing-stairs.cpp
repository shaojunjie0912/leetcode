#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
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

// NOTE: 0 ~ n 阶台阶, 楼梯顶部是 n + 1, 在 n 阶支付费用 cost[n] 即可到楼顶
// NOTE: 打家劫舍是 0 ~ n - 1, 这里爬楼梯是 0 ~ n

// dfs(i): 从 0 或 1 爬到 i 的最小花费

// 枚举哪一个 (枚举最后一步爬了几个台阶)
// - 最后一步爬了 1 个台阶, 即最小花费 dfs(i - 1) + cost[i - 1]
// - 最后一步爬了 2 个台阶, 即最小花费 dfs(i - 2) + cost[i - 2]

// dfs(i) = min(dfs(i - 1) + cost[i - 1], dfs(i - 2) + cost[i - 2])
// 边界: dfs(0) = 0, dfs(1) = 0 因为可以选择从 0/1 开始爬
// 入口: dfs(n)

// @leet start
class Solution {
    enum Method {
        DFS_MEMO,  // 递归 + 记忆化搜索
        DP_F,      // 递推 (普通 f 数组)
        DP_NEW_F,  // 递推 (只用三个状态)
    };

public:
    int minCostClimbingStairs(vector<int>& cost) {
        Method method{DP_NEW_F};
        switch (method) {
            case DFS_MEMO: {
                return SolveDfsMemo(cost);
            }
            case DP_F: {
                return SolveDpF(cost);
            }
            case DP_NEW_F: {
                return SolveDpNewF(cost);
            }
        }
    }

private:
    // dfs(i) = min(dfs(i - 1) + cost[i - 1], dfs(i - 2) + cost[i - 2])
    int SolveDfsMemo(vector<int>& cost) {
        int n = cost.size();
        vector memo(n + 1, -1);  // 记忆数组 0 ~ n, 一共 n + 1 个
        auto dfs = [&](auto&& self, int i) {
            if (i <= 1) {
                return 0;
            }
            auto& res = memo[i];
            if (res != -1) {
                return res;
            }
            return res = min(self(self, i - 1) + cost[i - 1], self(self, i - 2) + cost[i - 2]);
        };
        return dfs(dfs, n);
    }

    // f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2])
    int SolveDpF(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n + 1);
        f[0] = 0;
        f[1] = 0;
        //
        for (int i = 2; i <= n; ++i) {
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        }
        return f[n];
    }

    // f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2])
    int SolveDpNewF(vector<int>& cost) {
        int n = cost.size();
        int f0 = 0;  // 上上个
        int f1 = 0;  // 上个
        int new_f;
        for (int i = 2; i <= n; ++i) {
            new_f = min(f1 + cost[i - 1], f1 + cost[i - 2]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};
// @leet end

int main() { return 0; }
