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
    int maxProfit(vector<int>& prices) {
        int ans{0};
        int left_min{INT_MAX};  // 左边最小价格 (不包含当前)
        for (auto& x : prices) {
            ans = max(ans, x - left_min);
            left_min = min(left_min, x);
        }
        return ans;
    }
};
// @leet end
