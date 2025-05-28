#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
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

// 滑窗用一个 i 即可
// 定长滑窗 + c++ std::array 查表, p 一个表, s 一个表, 能用 == 比较
// array 大小为 26, 无论是<入>还是<出>小写字母需要减去 'a'
// 答案是滑窗左边界索引即 i - k + 1

// @leet start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();  // 滑窗大小
        vector<int> ans;
        std::array<int, 26> cnt_p{};  // p 中每个字符出现次数
        for (auto c : p) {
            ++cnt_p[c - 'a'];
        }
        std::array<int, 26> cnt_s{};  // s 的字串中每个字符出现次数
        for (int i{0}; i < n; ++i) {
            // 入
            ++cnt_s[s[i] - 'a'];
            // 不够窗口大小就 continue
            if (i < k - 1) {
                continue;
            }
            // 更新答案
            if (cnt_p == cnt_s) {  // std::array 支持 == 比较
                ans.push_back(i - k + 1);
            }
            // 出
            --cnt_s[s[i - k + 1] - 'a'];
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
