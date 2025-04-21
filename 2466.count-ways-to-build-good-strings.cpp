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

// 「爬楼梯」
// 每次可以爬 zero/one 个台阶, 求爬 low ~ high 之间台阶的方案数
// f[i] = f[i - zero] + f[i - one]
// sum(f[j]), low <= j <= high
// 边界条件: f[0] = 1, 空字符串啥也不做也是一种方案

// @leet start
class Solution {
    enum Method {
        DFS_MEMO,
        DP_F,
    };
    static constexpr int MOD = 1'000'000'007;

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        Method method{DP_F};
        switch (method) {
            case DFS_MEMO: {
                return SolveDfsMemo(low, high, zero, one);
            }
            case DP_F: {
                return SolveDpF(low, high, zero, one);
            }
        }
    }

private:
    // f[i] = f[i - zero] + f[i - one]
    // sum(f[j]), low <= j <= high
    int SolveDfsMemo(int low, int high, int zero, int one) {
        vector memo(high + 1, -1);  // 记忆数组, 大小为 high + 1
        auto dfs = [&](auto&& self, int i) {
            // 去除 step > i 的情况, 也可以在 for 循环中加 step<=i 条件
            // 但是递归可以加这里最上面
            if (i < 0) {
                return 0;
            }
            if (i == 0) {
                return 1;
            }
            auto& res = memo[i];
            if (res != -1) {
                return res;
            }
            // NOTE: 取模
            return res = (self(self, i - zero) + self(self, i - one)) % MOD;
        };
        int ans{0};
        for (int i = low; i <= high; ++i) {
            ans = (ans + dfs(dfs, i)) % MOD;  // NOTE: (ans + dfs)后取模
            // 不能是 ans += (dfs(dfs, i) % MOD);
        }
        return ans;
    }

    // f[i] = f[i - zero] + f[i - one]
    // sum(f[j]), low <= j <= high
    int SolveDpF(int low, int high, int zero, int one) {
        vector<int> f(high + 1, 0);  // f 数组
        f[0] = 1;                    // 初值
        for (int i = 1; i <= high; ++i) {
            // NOTE: 额外做 zero/one <= i 的约束 (其实就是递归中排除入参 < 0 情况)
            if (zero <= i) {
                f[i] = (f[i] + f[i - zero]) % MOD;
            }
            if (one <= i) {
                f[i] = (f[i] + f[i - one]) % MOD;
            }
        }
        int ans{0};
        for (int i = low; i <= high; ++i) {
            ans = (ans + f[i]) % MOD;
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
