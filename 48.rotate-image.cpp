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

// 竖着看: 旋转前第 j 列元素 -> 旋转后第 j 行元素
// 横着看: 旋转前第 i 行元素 -> 旋转后第 n - 1 - i 列元素

// 顺时针旋转 90° = 转置 + 翻转每行

// @leet start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();  // 正方形

        // 转置: 按对角线翻转
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 翻转每行
        for (int i = 0; i < m; ++i) {
            ranges::reverse(matrix[i]);
        }
    }
};
// @leet end

int main() { return 0; }
