#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
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

// 二分查找
// NOTE: 对于 m 行 n 列矩阵: 将索引 i 转化为 matrix[i / n][i % n]

// @leet start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid / n][mid % n] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return (l < m * n) && (matrix[l / n][l % n] == target);
    }
};
// @leet end
