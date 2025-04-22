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

// 完全背包, 类比「零钱兑换」
// 总容量 capacity: n
// 每件物品体积 w[i]: 完全平方数
// 每件物品价值 v[i]: 1 (其实就是数量)

// 求最少数量: 即最小价值
// dfs(i, c) = min(dfs(i - 1, c), dfs(i, c - w[i]) + 1) NOTE: 别忘了 + 1 数量

// @leet start

// NOTE: 全局变量, 提前分配了 10000, 后续直接查表
constexpr int N = 10000;
int f[N + 1];

// NOTE: 定义匿名 lambda 并「立即执行」, _ 是返回值
auto _ = [] {
    //  因为求 min, 因此这里初始值注意一下
    ranges::fill(f, INT_MAX);  // ranges::fill
    f[0] = 0;
    // 直接用 i * i <= N 作为循环判断条件
    // NOTE: x 不能放在初始化和条件中, 否则死循环
    for (int i = 1; i * i <= N; ++i) {
        auto x = i * i;
        for (int c = x; c < N + 1; ++c) {  // 从 c >= x 处正序计算,
            f[c] = min(f[c], f[c - x] + 1);
        }
    }
    return 0;
}();

class Solution {
public:
    int numSquares(int n) { return f[n]; }
};
// @leet end

int main() { return 0; }
