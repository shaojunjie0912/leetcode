#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // NOTE: 本题不足窗口大小的都是 -1 这里很巧妙, 直接赋初值就是 -1
        // 因为开始时不足大小的窗口会跳过循环, 最后右边界靠边即结束
        vector<int> ans(nums.size(), -1);
        int64_t sum{0};  // HACK: 害怕溢出
        // 滑动窗口大小: 2k + 1
        for (int i = 0; i < nums.size(); ++i) {  // 入
            sum += nums[i];
            // 不足窗口大小则跳过
            if (i < 2 * k) {
                continue;
            }
            // 更新
            // NOTE: i 是右边界, 而本题要记录中点, 所以是 ans[i-k]
            ans[i - k] = sum / (2 * k + 1);

            // 出
            sum -= nums[i - 2 * k];
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
