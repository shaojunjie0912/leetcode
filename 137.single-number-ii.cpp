#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return Find(nums, 3);
    }
    int Find(vector<int>& nums, int m) {
        // cnts[i]: 所有数在 i 位置上的 1 个数之和
        int cnts[32]{};
        for (auto num : nums) {
            for (int i = 0; i < 32; ++i) {
                // NOTE: 右移妙用
                cnts[i] += (num >> i) & 1;  // 统计每一位上是否为 1
            }
        }
        int ans{0};
        for (int i = 0; i < 32; ++i) {
            // 如果对应位的 1 总数无法被 m 整除, 则是出现 k 次的
            // 则该位应该是 1
            if (cnts[i] % m != 0) {
                // NOTE: 左移妙用
                ans |= 1 << i;
            }
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
