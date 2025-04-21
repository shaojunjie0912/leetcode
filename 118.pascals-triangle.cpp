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

// - 每一排首尾两个数都是 1
// - 其余数 = 左上方数 + 正上方数
// res[row][col] = res[row - 1][col - 1] + res[row - 1][col];

// @leet start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);  // 提前生成 numRows 行
        for (int row = 0; row < numRows; ++row) {
            res[row].resize(row + 1, 1);  // NOTE: resize 妙用, 正好首尾是 1
            for (int col = 1; col < row; ++col) {
                res[row][col] = res[row - 1][col - 1] + res[row - 1][col];
            }
        }
        return res;
    }
};
// @leet end

int main() { return 0; }
