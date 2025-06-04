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
        stack<int> st;  // 单调栈, 存放索引
        vector<int> ans(n);

        // 从右到左
        for (int i = n - 1; i >= 0; --i) {
            int t = temperatures[i];
            // 只要栈不为空且当前 t >= 栈顶, 就弹出栈
            while (!st.empty() && t >= temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            st.push(i);  // 入栈
        }

        return ans;
    }
};
// @leet end
