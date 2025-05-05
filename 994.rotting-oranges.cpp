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

// BFS 广度优先搜索

// @leet start
class Solution {
    // 上下左右
    const int DIRECTIONS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 先统计腐烂橘子的坐标, 以及新鲜橘子的个数
        queue<pair<int, int>> q;  // 腐烂橘子坐标
        int fresh{0};             // 新鲜橘子数量

        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto x{grid[i][j]};
                if (x == 1) {
                    ++fresh;
                } else if (x == 2) {
                    q.emplace(i, j);
                }
            }
        }

        int ans{0};
        // 开始模拟橘子腐烂过程
        // 循环直到 1. 没有新鲜橘子 或 2. q 为空
        // NOTE: 因为要最少时间, 因此 fresh 为 0 立即提前返回
        while (fresh && !q.empty()) {
            ++ans;                // 经过一分钟
            int size = q.size();  // NOTE: 每次处理一整轮的!!
            while (size--) {
                // 遍历 q, 把四个方向橘子腐烂, 并更新新一轮的腐烂橘子
                auto [rotten_x, rotten_y]{q.front()};
                q.pop();
                // 四个方向腐烂, 更新新一轮腐烂橘子
                for (auto const& [dir_x, dir_y] : DIRECTIONS) {
                    auto i = rotten_x + dir_x;
                    auto j = rotten_y + dir_y;
                    // NOTE:
                    // 1. 越界判断
                    // 2. 新鲜橘子才腐烂
                    if (0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;   // 新鲜橘子 -> 腐烂
                        q.emplace(i, j);  // 增加下一轮腐烂坐标
                        --fresh;          // 新鲜橘子 --
                    }
                }
            }
        }

        return fresh ? -1 : ans;  // 如果最后还有新鲜橘子, 说明不可能全部腐烂
    }
};
// @leet end
