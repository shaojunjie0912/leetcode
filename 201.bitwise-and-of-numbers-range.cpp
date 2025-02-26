#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // HACK: 复杂度很低, int 32 位
        while (right > left) {
            // NOTE: 如果 r > l, 则最右侧 1 留不下, 需要剥除
            // 这里 -right[-2^31 + 1, 0] 不会溢出
            right -= right & -right;  // BK 算法
        }
        // 如果 l==r 相等, 直接返回 r
        return right;
    }
};
// @leet end

int main() {
    return 0;
}
