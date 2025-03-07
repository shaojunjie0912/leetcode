#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
#if 1
    // 方法一: 两个辅助栈, 一个存乘数, 一个存字符串
    string decodeString(string s) {
        stack<int> multi_stack_;
        stack<string> res_stack_;
        string multi;  // NOTE: 后面需要+=再 stoi
        string res;
        for (auto &ch : s) {
            if (('0' <= ch) && (ch <= '9')) {  // 乘数(HACK: 是 && 不是 ||)
                multi += ch;
            } else if (('a' <= ch) && (ch <= 'z')) {  // 英文字母(HACK: 是 && 不是 ||)
                res += ch;
            }
            // 遇到 '[' 则存储 multi 和 res, 再重置
            else if (ch == '[') {
                multi_stack_.push(stoi(multi));
                res_stack_.push(res);
                multi.clear();
                res.clear();
            }
            // 遇到 ']' 开始拼接
            else {
                // last_res是上个 [ 到当前 [ 的字符串: "3[a2[c]]" 中的 a
                // cur_multi是当前 [ 到 ] 内字符串的重复倍数: "3[a2[c]]" 中的 2
                auto last_res{res_stack_.top()};
                auto curr_multi{multi_stack_.top()};
                res_stack_.pop();
                multi_stack_.pop();
                // NOTE: res = last_res + cur_multi * res
                while (curr_multi--) {
                    last_res += res;
                }
                // NOTE: 这里res后面将作为last_res, 所以是正确的
                // 不要想着去重置
                res = last_res;
            }
        }
        return res;
    }
#else

#endif
};
// @leet end

int main() {
    string s{"3[a]2[bc]"};
    std::cout << Solution{}.decodeString(s) << '\n';
    return 0;
}
