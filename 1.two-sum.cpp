#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 关键是遍历每个 nums[j] 时
// 用哈希表查询左边是否出现过 target - nums[j]

// @leet start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::unordered_map<int, int> map;
        for (int j = 0; j < n; ++j) {
            // 有 -> 添加答案
            if (map.contains(target - nums[j])) {
                return {map[target - nums[j]], j};
            }
            // 没有 -> 插入键值对, 供剩下的 nums[j] 查询
            else {
                map[nums[j]] = j;
            }
        }
        return {};
    }
};
// @leet end

int main() { return 0; }
