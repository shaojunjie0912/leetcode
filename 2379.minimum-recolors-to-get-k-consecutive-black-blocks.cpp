#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 定长滑动窗口

// @leet start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min_op{INT_MAX};  // NOTE: 傻孩子! 初始化为INT_MAX
        int curr_op{0};       // 当前操作次数

        for (int i = 0; i < blocks.length(); ++i) {  // 右边界入
            // HACK: 思考: 即保证窗口内都是黑色
            if (blocks[i] == 'W') {  // 当前是白色, 则需要涂黑
                ++curr_op;
            }

            if (i < k - 1) {
                continue;
            }

            // 更新
            min_op = min(min_op, curr_op);

            // 左边界出
            if (blocks[i - k + 1] == 'W') {
                --curr_op;
            }
        }
        return min_op;
    }
};
// @leet end

int main() {
    return 0;
}
