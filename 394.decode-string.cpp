#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 两个辅助栈, 一个存乘数, 一个存字符串

// @leet start
class Solution {
public:
    string decodeString(string s) {
        string res{};
        int num;
        stack<int> nums;
        stack<string> strs;
        for (auto& ch : s) {
            // 数字
            if ('0' <= ch && ch <= '9') {
                // NOTE: 加一个数字前需要把之前的 num 乘以 10
                num = num * 10 + ch - '0';
            }
            // 字母
            else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
                res += ch;
            }
            // 左括号 [
            else if (ch == '[') {
                // 入栈
                nums.push(num);
                strs.push(res);
                // 清空
                num = 0;
                res = "";
            }
            // 右括号 ]
            else {
                // 结算
                int repeat = nums.top();  // 数字倍数
                nums.pop();
                while (repeat--) {
                    // 把内部 [] 即 res 重复加到外部 str 即strs.top() 上
                    strs.top() += res;
                }
                // 此时原外部 [] 就是现在的 内部 []
                res = strs.top();
                strs.pop();
            }
        }
        return res;
    }
};
// @leet end

int main() {
    string s{"3[a]2[bc]"};
    std::cout << Solution{}.decodeString(s) << '\n';
    return 0;
}
