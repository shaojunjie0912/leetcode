#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    bool isPowerOfThree(int n) {
        // n 必须只含有 3 这个质数因子
        // 1162261467 是 int 型范围内，最大的 3 的幂，它是3的19次方
        return n > 0 && 1162261467 % n == 0;
    }
};
// @leet end

int main() {
    return 0;
}
