#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

using ll = long long;

// @leet start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 假设为 a 和 b, 则 a^b = xor_sum
        // long long 防止当 xor_sum = INT_MIN 时后面计算 -xor_sum 溢出
        ll xor_sum = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<>{});
        // a 和 b 不同 -> xor_sum 至少有一位是 1
        // 找到 xor_sum 最右边那个 1
        // diff 是一个只有一位为 1 的数, 就是最右边的 1
        ll diff = xor_sum & (-xor_sum);

        int a{0};
        int b{0};
        // 按照差异位上是 1 还是 0 对 nums 进行分组
        // 对应组直接异或和, 出现两次的就消掉了, 剩下就是答案
        for (auto x : nums) {
            // NOTE: 只能跟 0 对比(00000...)
            // NOTE: 加括号!!
            if ((x & diff) == 0) {
                a ^= x;
            } else {
                b ^= x;
            }
        }
        return {a, b};
    }
};
// @leet end

int main() { return 0; }
