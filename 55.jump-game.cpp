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

// 维护最右可达位置

// @leet start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_right{0};
        for (int i = 0; i < n; ++i) {
            // 如果当前 i 大于最右可达位置, 则 false
            if (i > max_right) {
                return false;
            }
            max_right = max(max_right, i + nums[i]);
        }
        return true;
    }
};
// @leet end
