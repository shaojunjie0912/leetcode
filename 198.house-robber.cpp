#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 普通回溯的时间复杂度是指数级的!
// 时间复杂度计算: 状态个数 * 单个状态计算时间 = O(n) * O(1)  = O(n)

// 「递归」如何改为「递推」?
// * dfs -> f 数组
// * 递归 -> 循环
// * 递归边界 -> 数组初始值

// @leet start
class Solution {
    enum Method {
        DP_MEMO,   // 递归(回溯) + 记忆化搜索 时间: O(n), 空间O(n)
        DP_F,      // 递推 (普通 f 数组) 时间: O(n), 空间O(n)
        DP_NEW_F,  // 递推 (只用三个状态) 时间: O(n), 空间O(1)
    };

public:
    int rob(vector<int>& nums) {
        Method method{DP_NEW_F};
        switch (method) {
            case DP_MEMO: {
                return Memo(nums);
            }
            case DP_F: {
                return F(nums);
            }
            case DP_NEW_F: {
                return NewF(nums);
            }
        };
    }

private:
    // 递归(回溯)(不选/选) + 记忆化搜索
    // 当前操作: 枚举「第 i 个」不选/选
    // dfs(i) = max(dfs(i-1), dfs(i-2)+nums[i])
    // dfs(i): 从「前 i 个」得到的最大金额
    int Memo(vector<int>& nums) {
        int n = nums.size();
        // 记忆数组 (n 个状态)
        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if (i < 0) {
                return 0;
            }
            if (memo[i] != -1) {
                return memo[i];
            }
            return memo[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]);
        };
        return dfs(n - 1);  // 入口: n - 1
    }

    // 递推 (普通 f 数组)
    // f[i] = max(f[i-1], f[i-2] + nums[i])
    // 处理边界从 2 开始 ↓
    // f[i+2] = max(f[i+1], f[i] + nums[i])
    int F(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 2);  // NOTE: 这里加 2, 初始值都是 0
        for (int i = 0; i < n; ++i) {
            f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        }
        return f[n + 1];  // n + 1 是最后一个状态
    }

    // 递推 (只用三个状态)
    int NewF(vector<int>& nums) {
        int n = nums.size();
        int f0{0};  // 上上个状态
        int f1{0};  // 上个状态
        int new_f;  // 当前状态
        for (auto x : nums) {
            new_f = max(f1, f0 + x);
            f0 = f1;     // 更新状态
            f1 = new_f;  // 更新状态
        }
        return new_f;
    }
};
// @leet end

int main() { return 0; }
