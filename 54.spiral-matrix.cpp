#include <algorithm>
#include <array>
#include <climits>
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

// 顺时针螺旋顺序: 右->下->左->上

// @leet start
class Solution {
    // 右->下->左->上 方向数组 (i 行, j 列变化)
    static constexpr int DIRS[4][2] = {
        {0, 1},   // 右 →
        {1, 0},   // 下 ↓
        {0, -1},  // 左 ←
        {-1, 0},  // 上 ↑
    };

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m * n);

        int i = 0, j = 0;
        int di = 0;  // 方向选择, 开始是右, 然后 (di+1)%4 代表右转 90°

        // 开始填充 m * n 个元素
        for (int k = 0; k < m * n; ++k) {
            ans[k] = matrix[i][j];
            matrix[i][j] = INT_MAX;  // 标记已访问

            // 计算下一步位置
            int x = i + DIRS[di][0];
            int y = j + DIRS[di][1];

            // 如果「下一步」到达边界或者已经访问过, 则右转 90°
            if ((x < 0 || x >= m || y < 0 || y >= n) || matrix[x][y] == INT_MAX) {
                di = (di + 1) % 4;
            }
            i += DIRS[di][0];
            j += DIRS[di][1];
        }

        return ans;
    }
};
// @leet end

int main() { return 0; }
