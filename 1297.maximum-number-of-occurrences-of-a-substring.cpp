#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 好像有一个滚动哈希? 暂时不会

// HACK: 感觉跟字符串相关的好像滑窗效果不大？
// 除非优化采用得到吧, 其他用 string_view 和 substr 好像就可以

// 这里 maxSize 是干扰项,
// 因为长度为 maxSize 的子串再切分成更小的子串
// 那数量肯定 >=, 因此只要数 minSize 即可

// @leet start
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int max_occur{0};                          // 最大出现次数
        unordered_map<string_view, int> curr_map;  // NOTE: 哈希表记录出现次数
        string_view sv{s};

        for (int i = 0; i + minSize - 1 < s.size(); ++i) {
            auto curr_str{sv.substr(i, minSize)};
            // HACK: 神奇, 直接从字符串构造char的哈希集合!!!
            unordered_set<char> exist{begin(curr_str), end(curr_str)};  // 不重复字符要求
            if (exist.size() <= maxLetters) {
                ++curr_map[curr_str];
                // NOTE: 自己还最后傻傻的遍历检索, 其实这里就可以比较再更新
                max_occur = max(max_occur, curr_map[curr_str]);
            }
        }

        return max_occur;
    }
};
// @leet end

int main() {
    return 0;
}
