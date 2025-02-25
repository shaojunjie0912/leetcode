#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // NOTE: 异或和性质:
        // 整体异或和为 x, 整体中某部分异或和为 y,
        // 则剩下部分异或和是 x ^ y
        int eor_has{0};  // 数组重已有数字的异或和
        int eor_all{0};  // 区间 [0, n] 所有数字的异或和
        for (int i = 0; i < nums.size(); ++i) {
            eor_has ^= nums[i];
            eor_all ^= i;
        }
        eor_all ^= nums.size();  // HACK: 最后把长度 n 加上
        return eor_all ^ eor_has;
    }
};
// @leet end

int main() {
    return 0;
}
