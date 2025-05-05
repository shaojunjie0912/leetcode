#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
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

// dfs 时把访问过格子的插上旗子🚩 标记为 '2'

// 每到一个格子可以向 上/下/左/右 走
// dfs 的输出参数为, 输出为 void

// @leet start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans{0};
        int m = grid.size();
        int n = grid[0].size();
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            // 边界条件
            // 1. 基本的上下左右边界(< 0, >= m/n), 不需要额外 +1 -1
            // 2. 如果遇到 '0' 说明不是陆地, '2' 说明已经访问过
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
                return;
            }

            grid[i][j] = '2';  // 标记为已访问

            dfs(i - 1, j);  // 上
            dfs(i + 1, j);  // 下
            dfs(i, j - 1);  // 左
            dfs(i, j + 1);  // 右
        };

        // 遍历开始插旗, 并更新答案
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 如果遇到 '1' 说明遇到一个新岛可以插旗
                if (grid[i][j] == '1') {
                    dfs(i, j);  // 递归直到将这个岛屿插满旗子🚩
                    ++ans;      // 答案 +1
                }
            }
        }

        return ans;
    }
};
// @leet end
