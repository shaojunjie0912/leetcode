#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 对于每个比特位 i, 遍历数组中每个数字, 累加第 i 位上的值
// 出现三次的数在该位上的累加是 3 的倍数
// total_i % 3 取模就是出现一次的数在该位的值 0/1

// @leet start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int32_t ans{0};  // 初始化时每一位都是 0
        // NOTE: 最外层循环是遍历整数32位
        for (int i = 0; i < 32; ++i) {
            int total_i = 0;  // 累加第 i 位上的值
            for (auto x : nums) {
                total_i += (x >> i) & 1;
            }
            // 如果取模不是 0 说明那个数字第 i 位是 1
            if (total_i % 3 != 0) {
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
