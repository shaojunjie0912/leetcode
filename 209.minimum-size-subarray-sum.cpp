#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 滑动窗口
    // 子数组: 是数组中<连续>的非空元素序列
    // 从 0 开始, 想让右边进来, 再判断能不能让左边出去
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;  // HACK: 坑: 不能设为0, 否则底下求min就不对了
        int l = 0;
        int r = 0;
        int sum = 0;
        // 循环一直让窗口向右扩大
        while (r < nums.size()) {
            // 思考: 刚开始[] 先往右扩 [0, 0]
            sum += nums[r];  // 往右扩
            // ================== 步骤1 ==================
            while (sum - nums[l] >= target) {  // 左边往右缩
                // sum : nums[l....r]
                // 如果l位置的数从窗口出去，还能继续达标，那就出去
                sum -= nums[l++];
            }
            // HACK: 步骤 1 和 2 不能颠倒, 否则 2 中窗口大小就不对
            // ================== 步骤2 ==================
            // 如果当前窗口和不够, 就继续往右扩大
            if (sum >= target) {  // 如果窗口和满足条件就更新答案
                ans = min(ans, r - l + 1);
            }
            ++r;
        }
        return ans == INT_MAX ? 0 : ans;  // 如果没找到, 要把ans从INT_MAX修改为0表示没有
    }
};
// @leet end

int main() {
    return 0;
}
