#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE:
// 1. 条件是乘积 < k, 不是常见的 >=
// 2. 子数组!! 一个子数组可以继续拆分
// 如果 [l,r] 乘积小于 k
// 则 [l+1, r], [l+2, r]...[r, r] 都小于 k
// 总个数就是 r - l + 1

// @leet start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // NOTE: 提前判断(也很重要) 正整数乘积不可能 < k(1)
        if (k <= 1) {
            return 0;
        }
        int ans{0};
        int product{1};
        for (int l{0}, r{0}; r < nums.size(); ++r) {
            product *= nums[r];
            while (product >= k) {  // NOTE: 这里还是判断 >= 然后缩小区间(即左端点右移)
                product /= nums[l++];
            }
            // 退出循环后, 或者不进循环, 就可以更新答案
            ans += r - l + 1;
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
