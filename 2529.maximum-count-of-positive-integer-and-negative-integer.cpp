#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // C++20:
    // ranges::lower_bound 第一个 >=
    // ranges::upper_bound 第一个 >

    // ================= 自己写的 ==================
    // 原来分了很多情况, 考虑(全正全负什么的,但是没必要)
    int maximumCount(vector<int>& nums) {
        int fist_pos = LowerBound(nums, 1);     // 第一个 >=1 的位置(后面全是正整数)
        int size_pos = nums.size() - fist_pos;  // 正整数数量

        int last_neg = LowerBound(nums, 0) - 1;  // 最后一个 < 0 的数(前面全都是负整数)
        int size_neg = last_neg + 1;             // 负整数数量

        // NOTE: !!!! 因为最后反正是 max, 哪怕全正/全负
        // 最后计算出来也是 0 跟剩下一个比较, 没影响!!!!
        return max(size_neg, size_pos);
    }

private:
    // 以 0 分割, 二分法, 尝试用红蓝染色思想, 答案在边界
    // 第一个 >= x 的元素索引
    int LowerBound(vector<int>& nums, int x) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @leet end

int main() {
    return 0;
}
