#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 处理字符串后先全部反转, 再一个单词一个单词反转
    // NOTE: O(1) 额外空间复杂度(原地修改)
    string reverseWords(string s) {
        // 1. 处理字符串
        RemoveSpace(s);
        // 2. 反转整个字符串
        ReverseStr(s, 0, s.length() - 1);
        // 3. 一个单词一个单词反转(双指针)
        for (int slow{0}, fast{0}; fast < s.length(); ++fast) {
            while (s[fast] != ' ' && fast < s.length()) {  // 条件
                ++fast;                                    // 抵达中间空格
            }
            ReverseStr(s, slow, fast - 1);  // 反转单词
            slow = fast + 1;                // 此时fast在空格, 所以slow要去下一个单词首
        }
        return s;
    }

private:
    // NOTE: 双指针移除字符串首尾及中间非必要空格, 在相邻单词之间添加空格
    void RemoveSpace(string& s) {
        int size{0};
        for (int slow{0}, fast{0}; fast < s.length(); ++fast) {
            if (s[fast] == ' ') {  // 跳过首尾空格以及非必要的中间空格
                continue;
            }
            if (slow != 0) {  // 添加必要的相邻单词间空格(slow=0时是首单词)
                s[slow++] = ' ';
                ++size;
            }
            // 内部循环处理每个单词, fast 遇到中间空格或者到最后一个单词就停止
            while (fast < s.length() && s[fast] != ' ') {
                s[slow++] = s[fast++];
                ++size;
            }
        }
        s.resize(size);  // HACK: 字符串resize
    }

    // 双指针按[区间]反转字符串
    void ReverseStr(string& s, int l, int r) {
        for (; l < r; ++l, --r) {
            swap(s[l], s[r]);
        }
    }
};
// @leet end

int main() {
    return 0;
}
