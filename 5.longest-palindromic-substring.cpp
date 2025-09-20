#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
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

// Manacher 马拉车算法
// O(n) O(n)

// @leet start
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() < 2) {
            return s;
        }

        // 1. 预处理字符串
        std::string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }

        int n = t.length();
        std::vector<int> radius(n, 0);  // radius[i] 表示以 t[i] 为中心的回文半径

        int max_right = 0;             // 已发现的回文串的最右边界
        int center_of_max_right = 0;   // 该回文串的中心
        int max_radius = 0;            // 最长回文子串在 t 中的半径
        int center_of_max_radius = 0;  // 最长回文子串在 t 中的中心

        // 2. 计算 radius 数组
        for (int i = 0; i < n; ++i) {
            // 利用已知信息初始化 radius[i]
            if (i < max_right) {
                // radius[2 * center - i] 是 i 关于 center 的对称点 j 的回文半径
                radius[i] = std::min(radius[2 * center_of_max_right - i], max_right - i);
            } else {
                radius[i] = 1;  // i >= max_right, 无法利用历史信息，半径至少为1（自身）
            }

            // 在初始值基础上继续暴力扩展
            while (i - radius[i] >= 0 && i + radius[i] < n &&
                   t[i - radius[i]] == t[i + radius[i]]) {
                radius[i]++;
            }

            // 更新 max_right 和 center
            if (i + radius[i] > max_right) {
                max_right = i + radius[i];
                center_of_max_right = i;
            }

            // 记录最长回文串信息
            if (radius[i] > max_radius) {
                max_radius = radius[i];
                center_of_max_radius = i;
            }
        }

        // NOTE: 映射!!!!
        // 3. 从 t 映射回 s
        // t 中的半径 max_radius 对应的 s 的总长度是 max_radius - 1
        // 在 t 中的起始索引是 center_of_max_radius - (max_radius - 1)
        // 映射回 s 中的起始索引是 (center_of_max_radius - max_radius + 1) / 2
        int start_s = (center_of_max_radius - max_radius + 1) / 2;
        int len_s = max_radius - 1;

        return s.substr(start_s, len_s);
    }
};
// @leet end
