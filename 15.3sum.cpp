#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE:
// 排序 + 双指针, 转化为两数之和: nums[j] + nums[k] == -nums[i]
// 外部循环遍历每一个 i (0 ~ n-3), 内部循环 j 从 i+1 开始, k 从 n-1 开始
// i    i + 1        n - 1
// i      j ->      <- k

// 外部循环: 一开始跳过重复的 i
// 内部循环: 在 == 0 的时候, 跳过重复的 j 和 k

// 两个小优化:
// 1. 跟最小两数相加都 > 0   HACK: break
// 2. 跟最大两数相加都 < 0   HACK: continue

// @leet start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        // 留下 size-2 和 size-1 给 j,k
        for (int i{0}; i < n - 2; ++i) {
            // 跳过重复的 i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 优化:
            // 1. 跟最小两数相加都 > 0   HACK: break
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
                break;
            }
            // 2. 跟最大两数相加都 < 0   HACK: continue
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) {
                continue;  // 直接右移 i, 让他变大, 才能和==0
            }

            int j{i + 1};
            int k{n - 1};
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    --k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    // NOTE: 只有在满足条件的分支才去重!!
                    // 不符条件分支意义不大, 因为能快速迭代到下一轮
                    // NOTE: 三元组是值不是索引!
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // 跳过重复的 j (额外条件: j < k)
                    ++j;
                    while (j < k && nums[j] == nums[j - 1]) {  // 遇到跟左边重复的 j 直接跳过
                        ++j;
                    }
                    // 跳过重复的 k (额外条件: j < k)
                    --k;
                    while (j < k && nums[k] == nums[k + 1]) {  // 遇到跟右边重复的 k 直接跳过
                        --k;
                    }
                }
            }
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
