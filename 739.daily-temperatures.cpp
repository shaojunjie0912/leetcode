#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
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

// 栈顶: 低温度
// 栈底: 高温度
// 维护一个递减的单调栈 (栈中存放索引!)
// 当处理第 i 天的温度时, 需要回顾之前哪些天正在「等待」一个更高的温度

// 遍历到新的一天 i 时, 如果 temperatures[i] 比栈顶索引对应的温度高,
// 则说明我们为栈顶的那一天找到了答案!!

// NOTE: 虽然 i 顺序遍历, 但是 prev_idx 更新答案是乱序的

// @leet start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            // NOTE: 这里比较值不是索引!!
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                auto prev_idx{st.top()};
                // 为栈顶的那一天(之前的某一天)找到了答案
                ans[prev_idx] = i - prev_idx;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
// @leet end
