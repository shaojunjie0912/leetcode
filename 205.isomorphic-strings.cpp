#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 不是直接对比出现次数!!而是映射字符
        // HACK:? 两层互相映射? -> 因为是双射!!(单射+满射) 一一对应
        // ASCII 0~127
        char s_map[128]{-1};  // 防止跟 ascii 0 冲突
        char t_map[128]{-1};
        for (int i{0}; i < s.length(); ++i) {
            s_map[s[i]] = t[i];  // s -> t 映射
            t_map[t[i]] = s[i];  // t -> s 映射
        }
        for (int i{0}; i < s.length(); ++i) {
            if (s_map[s[i]] != t[i] || t_map[t[i]] != s[i]) {
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
