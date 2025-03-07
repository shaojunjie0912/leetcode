#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 栈
    // 三种 false 情况
    // 1. 左括号多了: 当遍历完字符串时, 栈中还有元素
    // 2. 右括号多了: 当还没遍历完字符串时, 栈已经空了
    // 3. 左右括号不匹配: 遍历的当前括号跟栈顶(相反)对不上
    // HACK: 技巧: <匹配左括号>时, 用<对应的右括号入栈>, 这样就可以
    // 在遇到右括号时, 直接比较栈顶括号是否相同
    // <遇到右括号>这是通过不满足else if [, (, { 判断的
    // 所以不需要一个一个写右括号的判断条件
    bool isValid(string s) {
        // HACK: 提前判断: 奇数直接false
        if ((s.length() & 1) == 1) {
            return false;
        }
        stack<char> ch_stack;
        for (auto& ch : s) {
            // 遇 ( 入 )
            if (ch == '(') {
                ch_stack.push(')');
            }
            // 遇 { 入 }
            else if (ch == '{') {
                ch_stack.push('}');
            }
            // 遇 [ 入 ]
            else if (ch == '[') {
                ch_stack.push(']');
            }
            // NOTE: 检查
            // 1. 遍历字符串期间栈空(说明右括号多了)
            // 2. 是否匹配
            // HACK: 栈空条件在前!!!(否则top报错)
            else if (ch_stack.empty() || ch != ch_stack.top()) {
                return false;
            }
            // 该分支说明匹配成功, 弹出栈顶括号
            else {
                ch_stack.pop();
            }
        }
        // 遍历字符串后栈不空(说明左括号多了)
        if (!ch_stack.empty()) {
            return false;
        }
        return true;
    }
};
// @leet end

int main() {
    return 0;
}
