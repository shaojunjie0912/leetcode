#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int firstUniqChar(string s) {
        // HACK: 返回的是唯一的字符在字符串中的索引!!
        // 数组模拟哈希表
        // 小写字母: a~z: 97~122
        int s_map[123]{0};  // NOTE: 得用int, 而不能uint16_t
        for (auto& ch : s) {
            ++s_map[ch];
        }
        // NOTE: 遍历s查询map
        for (int i{0}; i < s.length(); ++i) {
            if (s_map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @leet end

int main() {
    return 0;
}
