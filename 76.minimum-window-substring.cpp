#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 「涵盖」: s 的子串中每个字母出现的次数都 >= t 中每个字母出现的次数

// @leet start
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.length() < t.length() || t.empty()) {
            return "";
        }

        // 使用 vector 作为频率表，更符合 C++ 风格
        std::vector<int> needs(128, 0);
        for (char c : t) {
            ++needs[c];
        }

        // count: 还需要匹配的字符总数
        // l: 窗口左边界
        // min_len: 最小窗口长度
        // start_index: 最小窗口的起始索引
        int count = t.length();  // count==0相当于 IsCovered 判断
        int n = s.length();
        int min_len{n + 1}, start_index{0};

        int l = 0;
        for (int r = 0; r < n; ++r) {
            // 扩展窗口
            // 如果 s[r] 是 t 中的字符，则所需字符数 count 减 1
            if (needs[s[r]] > 0) {
                --count;
            }
            // 将 s[r] 对应的需求量减 1
            // 对于不在 t 中的字符，其 needs 值会变为负数
            --needs[s[r]];

            // 当 count 为 0 时，表示当前窗口 [l, r] 已经覆盖了 t
            while (count == 0) {
                // 更新最小窗口信息
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_index = l;
                }

                // 收缩窗口，尝试将左边界 l 右移
                // 将 s[l] 归还，需求量加 1
                ++needs[s[l]];
                // 如果归还后，s[l] 的需求量大于 0，
                // 说明它是一个必需字符，我们又开始欠这个字符了
                if (needs[s[l]] > 0) {
                    ++count;
                }
                ++l;  // 移动左边界
            }
        }

        return min_len <= n ? s.substr(start_index, min_len) : "";
    }
};
// @leet end

int main() { return 0; }
