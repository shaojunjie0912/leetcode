#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // NOTE: 异或和
        // a, b 出现奇数次, 则所有元素异或和就是 a^b
        int eor_ab = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<>{});
        // a != b, 则异或和的结果二进制状态必有一位是 1
        // NOTE: Brian Kernighan 算法 -> 000000..1..000
        int right_most_one = eor_ab & -eor_ab;
        // 按照这一位是否为 1 将所有元素分成两类, 取其中的一类元素异或和
        // 我取"这一位是 1"的一类
        int eor_is_one{0};
        for (auto& num : nums) {
            if ((num & right_most_one) != 0)  // HACK: 位运算优先级 < 不相等
            {
                eor_is_one ^= num;
            }
        }
        // eor_is_one 就是 a/b 其中一个
        return {eor_is_one, eor_ab ^ eor_is_one};
    }
};
// @leet end

int main() {
    return 0;
}
