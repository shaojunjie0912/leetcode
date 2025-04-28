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

// 根据矩阵的行列元素递增特性: 从右上角元素找

// @leet start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = n - 1;  // 右上角元素
        // 用 while 方便里面根据右上角元素大小改变 i 和 j
        while (i < m && j >= 0) {
            // 这一行都 < target, 不要这一行
            if (matrix[i][j] < target) {
                ++i;
            }
            // 这一列都 > target, 不要这一列
            else if (matrix[i][j] > target) {
                --j;
            }
            // bingo!
            else {
                return true;
            }
        }
        return false;
    }
};
// @leet end

int main() { return 0; }
