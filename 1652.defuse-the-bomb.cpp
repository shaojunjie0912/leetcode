#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 定长滑动窗口
// 卡住原因: 只能想到 k > 0 好做(滑窗从左往右移动), 但 k < 0 呢?
// HACK: 无论 k > 0 还是 k < 0 窗口都是向右移动
// HACK: 循环数组可以用取模获取越界的下一个

// @leet start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int curr_sum{0};
        for (int i = 0; i < code.size(); ++i) {
            // 入
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
