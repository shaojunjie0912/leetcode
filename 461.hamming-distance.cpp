#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int hammingDistance(int x, int y) {
#if 1
        return CountOnes(x ^ y);
#else
        // bitset 投机取巧嘿嘿!
        std::bitset<32> eor(x ^ y);
        return eor.count();
#endif
    }

public:
    // 统计 n 中 1 的位数
    int CountOnes(int n) {
        // NOTE:
        // 先长度为 1, 2, 4, 8, 16 计数
        // 再右移一位计数相加
        // HACK: 先0101区别于先1010?
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);   // 长度 1 -> 2
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);   // 长度 2 -> 4
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);   // 长度 4 -> 8
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);   // 长度 8 -> 16
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);  // 长度 16 -> 32
        return n;
    }
};
// @leet end

int main() {
    return 0;
}
