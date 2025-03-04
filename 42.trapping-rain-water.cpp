#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
#if 0
    // HACK: 解法一: lmax rmax 最大值辅助数组
    // 总雨水 = 所有柱子雨水之和
    // 任何位置 i 处柱子顶部雨水:
    // 跟 0 取最大是 i 柱可能最高, 求出来结果是负数, 肯定没有雨水
    // max{ min{0 ~ i-1最大高度, i+1 ~ n-1最大高度} - i 高度, 0}
    int trap(vector<int>& nums) {
        int n = nums.size();

        vector<int> lmax(n);           // 记录左侧 0 ~ i 最大值(提前遍历获取)
        lmax[0] = nums[0];             // 0 ~ 0 上最大值
        for (int i = 1; i < n; ++i) {  // 0 ~ i (1,2,3...) 最大值
            lmax[i] = max(lmax[i - 1], nums[i]);
        }

        vector<int> rmax(n);  // 记录右侧 i ~ n-1 最大值(提前遍历获取)
        rmax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rmax[i] = max(rmax[i + 1], nums[i]);
        }
        int ans = 0;
        // NOTE: i: 1 ~ n-2, 是因为 0 & n-1 柱子不可能有水
        // i 左侧: i - 1
        // i 右侧: i + 1
        for (int i = 1; i < n - 1; ++i) {
            ans += max(0, min(lmax[i - 1], rmax[i + 1]) - nums[i]);
        }
        return ans;
    }
#else
    // 解法二: 双指针
    int trap(vector<int>& nums) {}
#endif
};
// @leet end

int main() {
    return 0;
}
