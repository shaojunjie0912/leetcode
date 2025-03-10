#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 定长滑窗 + 循环数组
// 本题循环数组就是给右边界扩充了, 取模即可

// @leet start
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k{accumulate(begin(nums), end(nums), 0)};  // 滑窗大小就是 1 的个数
        // HACK: 如果窗口大小为 0, 直接返回(又遇到窗口为 0 受影响的情况了)
        if (k == 0) {  // 全是 0, 则不存在
            return 0;
        }
        int min_swap{INT_MAX};  // HACK: 最小值不能设 0!!!
        int curr_swap{0};

        // NOTE: 冷静思考边界: n + k - 1
        for (int i{0}; i < nums.size() + k - 1; ++i) {
            // 入
            if (nums[i % nums.size()] == 0) {  // NOTE: 取模
                ++curr_swap;
            }

            if (i < k - 1) {
                continue;
            }

            // 更新
            min_swap = min(min_swap, curr_swap);

            // 出
            if (nums[i - k + 1] == 0) {  // 总忘记这是左边界 i-k+1
                --curr_swap;
            }
        }
        return min_swap;
    }
};
// @leet end

int main() {
    return 0;
}
