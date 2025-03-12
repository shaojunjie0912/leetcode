#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 排序后相向双指针

// @leet start
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        ranges::sort(nums);
        int n = nums.size();
        int ans{0};

        int l{0};
        int r{n - 1};

        while (l < r) {
            if (nums[l] + nums[r] >= target) {
                --r;
            } else {
                ans += r - l;  // NOTE: 这里 l~r 范围内都满足条件
                ++l;
            }
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
