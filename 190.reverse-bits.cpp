#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // NOTE: for/while 循环没有赋值操作、算术操作、位运算快!!!
        // 所以思路for循环翻转不可取
        // HACK: 1v1, 2v2, 4v4, 8v8, 16v16 交换
        // NOTE: !!! 左移<<, 右移>> 优先级 > 按位与&, 加括号!!
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
        return n;
    }
};
// @leet end

int main() {
    return 0;
}
