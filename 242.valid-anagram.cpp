#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    bool isAnagram(string s, string t) {
        // NOTE: 长度不等直接返回
        if (s.length() != t.length()) {
            return false;
        }
        // unordered_map<char, int> s_map;
        // 测试还是数组好(快?至少测出来是这样,内存差不多))

        // 小写字母: a~z: 97~122
        int16_t s_map[123]{0};  // HACK: 不能用char, 因为int8_t不够
        for (auto const& ch : s) {
            ++s_map[ch];
        }
        for (auto const& ch : t) {
            // if (s_map[ch] == 0) { // 不加判断也一样
            //     return false;
            // }
            --s_map[ch];
        }
        for (auto& cnt : s_map) {
            if (cnt != 0) {
                return false;
            }
        }
        return true;
    }
};
// @leet end

int main() {
    return 0;
}
