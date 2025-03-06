#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: stl std::max_element 超时了
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int max_val{INT_MIN};
        for (int l{0}, r{k - 1}; r < nums.size(); ++l, ++r) {
            if (l == 0) {  // 第一组
                max_val = *std::max_element(nums.begin(), nums.begin() + k);
                continue;
            }
            max_val = max(max_val, nums[r]);
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
