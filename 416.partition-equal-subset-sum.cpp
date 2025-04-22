#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
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

// 0-1 背包, 选/不选, 类似 494.目标和
// 添加正号负号使得和=target=0
// p - (s - p) = 0
// p = s/2
// capacity = s/2

// dfs(i, c) = dfs(i - 1, c) + dfs(i - 1, c - w[i])
// f[i + 1][c] = f[i][c] + f[i][c - w[i]]
// f[c] = f[c] + f[c - w[i]]

// NOTE: 溢出怎么办?
// 题目是判断 bool, 其实就是两种方案是否有一种成立, 用或

// @leet start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 计算背包容量
        auto s = std::reduce(nums.begin(), nums.end());
        if (s % 2 == 1) {  // 如果是奇数则没有可行方案
            return false;
        }
        auto capacity = s / 2;
        // 一维 f 数组, f[c] = f[c] || f[c - w[i]], 倒序
        vector<int> f(capacity + 1);  // 貌似 vector<bool> 有问题, 先用 int
        f[0] = 1;                     // c = 0 时方案可行
        for (auto x : nums) {
            for (int c{capacity}; c >= x; --c) {
                f[c] = f[c] || f[c - x];  // NOTE: 把 + 改成用 ||
            }
        }
        return f[capacity];
    }
};
// @leet end

int main() { return 0; }
