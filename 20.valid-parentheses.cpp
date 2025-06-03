#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.length() % 2 == 1) {  // 奇数肯定不是
            return false;
        }
        for (auto ch : s) {
            // 遇左括号则对应的右括号入栈
            if (ch == '(') {
                st.push(')');
            } else if (ch == '[') {
                st.push(']');
            } else if (ch == '{') {
                st.push('}');
            } else {
                // 右括号
                // 匹配失败: 1. 栈为空(没有对应左括号) 2. 左右不匹配
                if (st.empty() || ch != st.top()) {
                    return false;
                }
                st.pop();  // 匹配成功则出栈
            }
        }
        return st.empty();  // NOTE: 妙: 栈空即完全匹配
    }
};
// @leet end

int main() { return 0; }
