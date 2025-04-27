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

// 前缀和
// 维护当前前缀和最小值, 因为 max(子数组和) = cur(前缀和) - min(前缀和)

// @leet start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans{INT_MIN};
        int min_pre_sum{0};
        int pre_sum{0};
        for (auto x : nums) {  // 直接范围 for
            pre_sum += x;
            // NOTE: 先计算 cur(前缀和) - min(前缀和)
            ans = std::max(ans, pre_sum - min_pre_sum);
            // 再更新 min (前缀和)
            min_pre_sum = std::min(min_pre_sum, pre_sum);
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
