#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 定长滑动窗口

// 循环中先进一个更新后再出一个

// 入 -> 更新 -> 出

// @leet start
class Solution {
public:
    // NOTE: 最后计算的最大!!max!! 所以要更新的也是 ans= max(ans, curr)
    // NOTE: 窗口大小不足 k 就 continue
    int maxVowels(string s, int k) {
        int ans{0};   // 最终结果(跟 curr 比较更新)
        int curr{0};  // 当前窗口结果

        // 是否是元音字母
        auto CheckVowel = [](char ch) -> bool {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
            return false;
        };

        // 只用一个变量 i 作为右边界, 因为有窗口大小辅助变量, 可以知道左边界
        for (int i{0}; i < s.length(); ++i) {  // 入(此时符合窗口大小)
            if (CheckVowel(s[i])) {            // 更新
                ++curr;
            }
            ans = std::max(ans, curr);  // HACK: 要更新 ans 最大值

            if (ans == k) {  // NOTE: 优化, 如果ans已经是最大值k了直接返回
                return ans;
            }

            if (i < k - 1) {  // HACK: 如果当前长度不足窗口大小, 则继续入!!
                // 感觉这个判断应该只针对第一个滑动窗口的形成
                // 因为第一个滑动窗口大小够了的话, 后面肯定都够
                continue;
            }

            // 出(又变成窗口大小-1)
            if (CheckVowel(s[i - k + 1])) {  // 窗口左边界
                --curr;
            }
        }
        return ans;
    }
};
// @leet end

int main() {
    string s = "abciiidef";
    int k = 3;
    cout << Solution{}.maxVowels(s, k) << '\n';
    return 0;
}
