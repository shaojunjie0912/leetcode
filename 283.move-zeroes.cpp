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

// @leet start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int room = 0;  // HACK: (始终维护) 最左边的空位
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {  // 当前数是 0 不操作
                continue;
            } else {  // 当前数非 0 则交换最左边空位和当前数
                std::swap(nums[room++], nums[i]);
            }
        }
    }
};
// @leet end

int main() { return 0; }
