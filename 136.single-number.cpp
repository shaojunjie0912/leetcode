#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // NOTE: 异或和: 结果就是只出现奇数次的元素
        // 偶数次的元素异或和是 0, 不影响异或和结果

        // ============ 1 =============
        // int eor_all{0};
        // for (auto& v : nums) {
        //     eor_all ^= v;
        // }
        // return eor_all;

        // ============ 2 =============
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<>());
    }
};
// @leet end

int main() {
    return 0;
}
