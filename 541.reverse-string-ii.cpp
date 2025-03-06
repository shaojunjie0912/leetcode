#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    string reverseStr(string s, int k) {
        // NOTE: 每次 i 都来到 2 * k 区间头部, 反转 i, i+k-1 即可
        for (int i = 0; i < s.length(); i += 2 * k) {
            int last = s.length() - i;  // 边界
            // HACK: 留心处理逻辑
            if (last >= k) {
                Reverse(s, i, i + k - 1);  // 反转前 k(其实一直到最后都这样)
            } else {
                // 除了最后不足 k
                Reverse(s, i, s.length() - 1);  // 反转剩下所有
            }
        }
        return s;
    }

    void Reverse(string& s, int l, int r) {
        for (; l <= r; ++l, --r) {
            std::swap(s[l], s[r]);
        }
    }
};
// @leet end

int main() {
    return 0;
}
