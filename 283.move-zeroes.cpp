#include <algorithm>
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

// NOTE: 将 0 视为可填入的空位, 将数移动到最左边空位
// 这题是有「移动」的要求, 因此用 swap

// @leet start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int room = 0;           // HACK: 维护最左边的空位索引
        for (auto& x : nums) {  // NOTE: 引用!!
            if (x) {            // 当前数非 0 则交换最左边空位和当前数
                std::swap(nums[room++], x);
            }
        }
    }
};
// @leet end

int main() { return 0; }
