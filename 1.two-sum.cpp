#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 哈希表

// @leet start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::unordered_map<int, int> map;
        for (int j = 0; j < n; ++j) {
            // 如果出现过 target - nums[j] 则返回答案
            if (map.contains(target - nums[j])) {
                return {map[target - nums[j]], j};
            }
            // 否则哈希表保存 (nums[j], index)
            else {
                map[nums[j]] = j;
            }
        }
        return {};
    }
};
// @leet end

int main() { return 0; }
