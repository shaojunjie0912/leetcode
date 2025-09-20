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

// @leet start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        // 主对角线上的元素索引规律: i+j = k 固定值
        // 遍历 k 即对角线 NOTE: 边界是 <=
        for (int k = 0; k <= m + n - 2; ++k) {
            // NOTE: 对于每条对角线, 计算 j 的范围, 基于 j = k - i
            int min_j = max(0, k - m + 1);  // 肯定要 >= 0, 其次 i 取最大
            int max_j = min(n - 1, k);      // 肯定要 <= n-1, 其次 i 取最小
            // k 为偶数: j 从小到大
            if (k % 2 == 0) {
                for (int j = min_j; j <= max_j; ++j) {
                    ans.push_back(mat[k - j][j]);
                }
            }
            // k 为奇数: 更换方向: j 从大到小
            else {
                for (int j = max_j; j >= min_j; --j) {
                    ans.push_back(mat[k - j][j]);
                }
            }
        }
        return ans;
    }
};
// @leet end
