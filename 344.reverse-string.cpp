#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 双指针
        // NOTE: 这里 l<r 不需要 =, 一个字符也不需要反转
        for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
            std::swap(s[l], s[r]);
        }
    }
};
// @leet end

int main() {
    return 0;
}
