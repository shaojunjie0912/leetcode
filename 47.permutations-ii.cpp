#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        R(nums, 0, ans);
        return ans;
    }

    // 增加去重逻辑即可
    void R(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> set;
        for (int j = i; j < nums.size(); ++j) {
            // NOTE: nums[j]没有来到过i位置才执行后续逻辑
            if (!set.contains(nums[j])) {
                set.insert(nums[j]);  // 加入到集合
                std::swap(nums[i], nums[j]);
                R(nums, i + 1, ans);
                std::swap(nums[j], nums[i]);
            }
        }
        return;
    }
};
// @leet end

int main() {
    return 0;
}
