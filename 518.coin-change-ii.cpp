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

// 完全背包, 选/不选
// dfs(i, c) = dfs(i - 1, c) + dfs(i, c - w[i])
// f[i+1][c] = f[i][c] + f[i+1][c-w[i]]
// f[c] = f[c] + f[c-w[i]]

// @leet start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // NOTE: int 溢出, 但是 uint32_t 溢出环绕后结果是对的
        vector<uint32_t> f(amount + 1);
        f[0] = 1;
        for (auto x : coins) {
            for (int c{x}; c < amount + 1; ++c) {
                f[c] = f[c] + f[c - x];
            }
        }
        return f[amount];
    }
};
// @leet end

int main() { return 0; }
