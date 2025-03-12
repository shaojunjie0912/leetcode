#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// nums[i] + nums[j] + nums[k] ≈ target
// nums[j] + nums[k] 最接近 target - nums[i]

// @leet start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ranges::sort(nums);
        int n = nums.size();
        int ans{0};             // 最终答案
        int min_diff{INT_MAX};  // 与 target 接近程度
        for (int i{0}; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {  // 优化1: 排除 i 重复
                continue;
            }

            // 优化2: 跟最小的两个相加都 > target, 后面不可能更接近
            int sum_min{nums[i] + nums[i + 1] + nums[i + 2]};
            if (sum_min > target) {
                // HACK: 如果更接近才更新
                if (sum_min - target < min_diff) {
                    ans = sum_min;
                }
                break;
            }

            // 优化3: 跟最大的两个相加都 < target, 则直接右移 i 变大试试
            int sum_max{nums[i] + nums[n - 2] + nums[n - 1]};
            if (sum_max < target) {
                // NOTE: 需要更新, 因为还要 continue 后面
                // HACK: 如果更接近才更新
                if (target - sum_max < min_diff) {
                    min_diff = target - sum_max;
                    ans = sum_max;
                }
                continue;
            }

            int j{i + 1};
            int k{n - 1};
            while (j < k) {
                int sum{nums[i] + nums[j] + nums[k]};
                if (sum > target) {
                    if (sum - target < min_diff) {
                        min_diff = sum - target;
                        ans = sum;
                    }
                    --k;
                } else if (sum < target) {
                    if (target - sum < min_diff) {
                        min_diff = target - sum;
                        ans = sum;
                    }
                    ++j;
                } else {
                    return sum;
                }
            }
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
