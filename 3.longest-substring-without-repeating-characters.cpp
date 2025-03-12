#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 思考: 右端点如果是重复值, 则破坏了条件
// 则需要左端点右移来使得区间重新符合条件
// 哪怕右端点只是跟中间某个字符重复
// 也应该缩小左端点, 首先, 已经记录了之前的长度,
// 其次, 题目就是要求连续, 跟中间重复肯定不连续

// @leet start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int curr_map[128]{};
        int ans{0};
        for (int l{0}, r{0}; r < s.size(); ++r) {
            ++curr_map[s[r]];
            while (curr_map[s[r]] > 1) {  // 如果右侧是重复字符, 则左端点一直右移
                // 思考: <左>端点右移是因为<右>端点之前出现过
                // 记得 --左端点字符计数
                --curr_map[s[l]];
                ++l;
            }
            ans = max(ans,
                      r - l + 1);  // 卡在没想到长度如何计算, 该放在循环后还是前
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}

// // NOTE: 滑动窗口
// // 子串: 连续
// // 当不重复最长子串窗口右边界来到 i 位置时, 如果 i 位置字符x之前出现过
// // 则更新左边界: max{当前左边界, 上一次 x 出现的地方 + 1}
// // HACK: 怎么知道字符上一次出现的位置? -> 用一个 int[256]
// int lengthOfLongestSubstring(string s) {
//     // 删除了0,1长度的判断代码, 下面逻辑已经覆盖
//     int l = 0;
//     int r = 0;
//     vector<int> last(256, -1);  // 每种字符上一次出现的位置
//     int ans = 0;
//     while (r < s.length()) {
//         // if (last[s[r]] != -1) {  // 当前字符之前出现过
//         l = std::max(l, last[s[r]] + 1);  // NOTE: 初始值为 -1, 所以不加判断也行
//         // }
//         last[s[r]] = r;  // 更新当前字符上一次出现的位置
//         ans = max(ans, r - l + 1);
//         ++r;
//     }
//     return ans;
// }
