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

// NOTE: 寻找一个最小的数 x，使得矩阵中小于等于 x 的元素个数恰好不小于 K
// 以元素值二分, 而不是索引二分

// @leet start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix.front().front();  // min: 左上角
        int r = matrix.back().back();    // max: 右下角
        // 统计 <= val 的元素数量
        auto count_less_than = [&](int val) -> int {
            // 从右上角开始统计
            int cnt{0};
            int i = 0, j = n - 1;
            while (i <= n - 1 && j >= 0) {
                // NOTE: 当前元素及左边所有元素都满足
                // NOTE: 只能加一边, 不能同时加左边和上面
                if (matrix[i][j] <= val) {  // NOTE: 符合条件
                    cnt += j + 1;           // 加左边
                    ++i;                    // 移动到下一行
                } else {                    // NOTE: 大了, 不符合条件
                    --j;                    // 移动到左一列
                }
            }
            return cnt;
        };
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (count_less_than(m) < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;  // 分界线 l 就是答案
    }
};
// @leet end
