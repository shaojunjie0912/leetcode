#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 简单做法: 不滑窗, 直接string_view的substr
// 遍历一遍

// 优化:
// 定长滑窗 + 哈希集合
// 不太一样, 涉及到字符串操作
// 长度为 k 的字符串加入哈希集合的时间复杂度为 O(k)
// 不如整数, 所以可以将二进制子串转为整数

// @leet start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string_view> curr_set;  // NOTE: string_view 对应

        string_view sv{s};

        for (int i = 0; i + k - 1 < s.length(); ++i) {
            curr_set.insert(sv.substr(i, k));
        }

        return curr_set.size() == (1 << k);
    }
};
// @leet end

int main() {
    return 0;
}
