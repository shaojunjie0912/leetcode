#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 双指针(遍历t, 遇到匹配字符才移动s)
    // HACK: 不能哈希表计数, 因为子序列不能改变相对位置
    bool isSubsequence(string s, string t) {
        // HACK: 怎么还有空字符串?
        if (s.empty()) {
            return true;
        }
        int sp{0};
        int tp{0};
        while (tp < t.size()) {
            if (s[sp] == t[tp]) {
                ++sp;
            }
            ++tp;
        }
        // 最后一个匹配成功后 sp 肯定越界 == size 了
        if (sp < s.size()) {  // HACK: 这里一开始写错 size-1
            return false;
        }
        return true;
    }
};
// @leet end

int main() {
    return 0;
}
