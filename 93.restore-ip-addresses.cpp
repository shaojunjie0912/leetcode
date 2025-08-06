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

// @leet start
class Solution {
public:
    // 三重循环 (三个切分点, 分成四段)
    // 0..i..j..k..n-1
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        // 提前判断返回
        if (n < 4 || n > 12) {
            return {};
        }
        vector<string> ans;
        // 判断闭区间 [l, r] 子串是否合法
        auto is_valid = [&](int l, int r) -> bool {
            // false: 长度超过 3 的子串或者多位但首位是 0
            if ((r - l + 1 > 3) || (r > l && s[l] == '0')) {
                return false;
            }
            return stoi(s.substr(l, r - l + 1)) <= 255;
        };
        for (int i = 0; i < n; ++i) {
            // 剪枝：如果第一段已经不合法，后续更长的第一段也必然不合法
            if (!is_valid(0, i)) {
                break;
            }
            for (int j = i + 1; j < n; ++j) {
                // 同理剪枝
                if (!is_valid(i + 1, j)) {
                    break;
                }
                // NOTE: k 不能是最后一个字符
                for (int k = j + 1; k < n - 1; ++k) {
                    // 同理剪枝
                    if (!is_valid(j + 1, k)) {
                        break;
                    }

                    // 如果第四段也合法就记录答案
                    // 最后 substr(k+1) 直接到最后
                    if (is_valid(k + 1, n - 1)) {
                        std::string ip{s.substr(0, i + 1) + "." + s.substr(i + 1, j - i) + "." +
                                       s.substr(j + 1, k - j) + "." + s.substr(k + 1)};
                        ans.push_back(ip);
                    }
                }
            }
        }
        return ans;
    }
};
// @leet end
