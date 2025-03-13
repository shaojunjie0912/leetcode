#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 遍历每一个方块, 想象成带左右两侧板的桶
// 桶的左侧板就是左侧最大高度, 右侧板就是右侧最大高度
// 取左右侧板较小值
// 1. 如果最小值 <= 当前方块本身高度, 则当前方块上没有雨水
// 2. 否则: 再减去方块本身的高度, 即当前方块雨水

// @leet start
class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int ans{0};

        // 前缀最大值数组(保存 0 ~ i 中最大值)
        vector<int> pre_max(n);
        pre_max[0] = nums[0];
        for (int i{1}; i < n; ++i) {
            pre_max[i] = max(nums[i], pre_max[i - 1]);  // NOTE: 比较当前 nums[i] 和 pre_max[i-1]
        }

        // 后缀最大值数组(保存 i ~ n-1 中最大值)
        vector<int> suf_max(n);
        suf_max[n - 1] = nums[n - 1];
        for (int j{n - 2}; j >= 0; --j) {
            suf_max[j] = max(nums[j], suf_max[j + 1]);  // NOTE: 比较当前 nums[i] 和 suf_max[j+1]
        }

        // 遍历每一个方块
        for (int k{0}; k < n; ++k) {
            ans += min(pre_max[k], suf_max[k]) - nums[k];
        }

        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
