#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // NOTE: 正数 + 只有一个 bit 1
        // Brian Kernighan 算法
        return n > 0 && n == (n & (-n));
    }
};
// @leet end

int main() {
    return 0;
}
