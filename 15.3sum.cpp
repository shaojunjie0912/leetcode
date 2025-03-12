#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE:
// 变有序后使用双指针
// 转化为两数之和: nums[j] + nums[k] == -nums[i]

// HACK:
// 卡在觉得 i 右移时, 左边的区域也应该给 j/k 搜索
// 但其实 i 每一次右移, 都会遍历右边所有
// i 左边的区域已经被之前的 i 试过了

// @leet start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        // NOTE: 留下 size-2 和 size-1 给 j,k
        for (int i{0}; i < n - 2; ++i) {
            // NOTE: 三元组不重复!!
            // 遇到跟左边重复的 i 直接跳过
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // NOTE: 之前写成while循环了!!, 只能跳最近一层!
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

            int j{i + 1};  // j->
            int k{n - 1};  //       <-k
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                // 跟两数之和一样的搜索方法
                // 但是这里额外增加不重复条件
                if (sum > 0) {
                    --k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // NOTE: 条件加了 j < k, 正常思路
                    ++j;
                    while (j < k && nums[j] == nums[j - 1]) {  // 遇到跟左边重复的 j 直接跳过
                        ++j;
                    }
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

int main() {
    return 0;
}
