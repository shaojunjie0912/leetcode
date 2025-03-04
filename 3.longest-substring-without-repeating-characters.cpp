#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 滑动窗口
    // 子串: 连续
    // 当不重复最长子串窗口右边界来到 i 位置时, 如果 i 位置字符x之前出现过
    // 则更新左边界: max{当前左边界, 上一次 x 出现的地方 + 1}
    // HACK: 怎么知道字符上一次出现的位置? -> 用一个 int[256]
    int lengthOfLongestSubstring(string s) {
        // 删除了0,1长度的判断代码, 下面逻辑已经覆盖
        int l = 0;
        int r = 0;
        vector<int> last(256, -1);  // 每种字符上一次出现的位置
        int ans = 0;
        while (r < s.length()) {
            // if (last[s[r]] != -1) {  // 当前字符之前出现过
            l = std::max(l, last[s[r]] + 1);  // NOTE: 初始值为 -1, 所以不加判断也行
            // }
            last[s[r]] = r;  // 更新当前字符上一次出现的位置
            ans = max(ans, r - l + 1);
            ++r;
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
