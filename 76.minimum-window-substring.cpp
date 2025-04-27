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

// NOTE: 特意封装了一个判断是否涵盖的函数 IsCovered, 也是很耗时的(因为逐个比较)

// @leet start
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int ans_left = -1, ans_right = n;  // ans (用出界值初始化)
        int cnt_s[128]{};                  // s 的子串中每个字母出现的次数
        int cnt_t[128]{};                  // t 中每个字母出现的次数
        // 记录 t 中每个字母出现次数
        for (auto c : t) {
            ++cnt_t[c];
        }
        for (int left = 0, right = 0; right < n; ++right) {
            // 右端点移入
            ++cnt_s[s[right]];
            // while 涵盖, 就尝试左端点移出, 缩小窗口
            while (IsCovered(cnt_s, cnt_t)) {
                // 更新答案 (更短的子串)
                if (right - left < ans_right - ans_left) {
                    ans_left = left;
                    ans_right = right;
                }
                // 左端点移出
                --cnt_s[s[left]];
                ++left;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }

private:
    bool IsCovered(int* cnt_s, int* cnt_t) {
        for (int i = 'A'; i <= 'Z'; ++i) {  // 有趣: int = char ''
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; ++i) {  // 有趣: int = char ''
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        return true;
    }
};
// @leet end

int main() { return 0; }
