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

// 最大 (子数组和) -> 最大 (前缀和之差) -> 「买卖股票最佳时机」

// @leet start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans{INT_MIN};
        int min_left{0};  // NOTE: 0: 因为下面循环从第一个开始遍历, 此时 min_left = s[0] = 0
        int pre_sum{0};
        for (auto& x : nums) {
            pre_sum += x;
            ans = std::max(ans, pre_sum - min_left);
            min_left = std::min(min_left, pre_sum);
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
