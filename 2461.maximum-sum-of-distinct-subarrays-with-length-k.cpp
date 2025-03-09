#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 定长滑动窗口+哈希表保证各不相同

// @leet start
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int64_t max_sum{0};
        int64_t curr_sum{0};
        unordered_map<int, int> curr_map;
        // unordered_set<int> curr_set;
        // 不能用set, 因为如果左边界是重复值, 则删除后就忘记了,
        // 但数组中还是存在的, 因此要用map的key-value办法
        for (int i = 0; i < nums.size(); ++i) {
            // 入
            curr_sum += nums[i];
            ++curr_map[nums[i]];

            if (i < k - 1) {
                continue;
            }

            // 更新
            if (curr_map.size() == k) {
                max_sum = max(max_sum, curr_sum);
            }

            // 出
            curr_sum -= nums[i - k + 1];
            if (--curr_map[nums[i - k + 1]] == 0) {
                curr_map.erase(nums[i - k + 1]);
            }
        }
        return max_sum;
    }
};
// @leet end

int main() {
    return 0;
}
