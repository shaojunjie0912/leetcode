#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
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

// @leet start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.length();
        vector<int> last_right(26);  // 字符最右边索引数组
        // 第一次遍历记录最右边索引
        for (int i = 0; i < n; ++i) {
            last_right[s[i] - 'a'] = i;
        }
        // start: 区间左端点
        // end: 区间右端点
        int start = 0, end = 0;
        // 第二次遍历合并区间
        for (int i = 0; i < n; ++i) {
            // 更新区间右端点
            end = max(end, last_right[s[i] - 'a']);
            // 如果 i==end 就说明合并结束!
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;  // 更新区间左端点
            }
        }
        return ans;
    }
};
// @leet end
