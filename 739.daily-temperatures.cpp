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

// 单调栈: 栈中存放索引

// @leet start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // 从右到左遍历
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            int t = temperatures[i];  // 获取当前温度
            // 如果当前温度>=栈顶元素, 就一直弹出
            while (!st.empty() && t >= temperatures[st.top()]) {
                st.pop();
            }
            // 这里当前温度 < 栈顶元素, 可以记录答案了
            // 注意: 栈不为空
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            // 记录索引到栈中
            st.push(i);
        }

        return ans;
    }
};
// @leet end
