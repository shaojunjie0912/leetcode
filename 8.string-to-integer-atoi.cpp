#include <algorithm>
#include <array>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <string>

using namespace std;

// 有限状态机思想 (不需要显式定义状态, 而是通过顺序逻辑模拟状态转移)
// 正序遍历过程中的计算方式: 当前结果 * 10 + 新的数字

// <cctype> isdigit

// @leet start
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i{0};
        int sign{1};     // 初始符号位 1
        int64_t ans{0};  // NOTE: int64_t 方便检测溢出

        // 1. 跳过「所有」前导空格
        while (i < n && s[i] == ' ') {
            ++i;
        }

        // 2. 处理正负号
        if (i < n) {  // i < n 是前提
            if (s[i] == '-') {
                sign = -1;
                ++i;
            } else if (s[i] == '+') {
                sign = 1;
                ++i;
            }
        }

        // 3. 转换数字并防止溢出 (i < n 是前提)
        // 非数字的字符直接退出
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // NOTE: 在累加前进行溢出检查
            // 检查正溢出和负溢出 (跟INT_MAX比较即可)
            if (ans * 10 + digit > INT_MAX) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            ans = ans * 10 + digit;
            ++i;  // NOTE: 索引递增!别忘了!
        }

        return static_cast<int>(sign * ans);  // 防止窄化转换
    }
};
// @leet end
