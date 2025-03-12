#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 出现次数 <=2
// 哈希表(可以数组替代)

// @leet start
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int map[128]{};
        int ans{0};
        for (int l{0}, r{0}; r < s.size(); ++r) {
            ++map[s[r]];
            while (map[s[r]] > 2) {  // 当由于右端点的进入而不满足条件时
                --map[s[l++]];       // 移动左端点, 使得再次符合条件
            }
            // 出循环后就是符合条件的, 更新 ans
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
