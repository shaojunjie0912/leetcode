#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
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

// @leet start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 按左端点排序
        ranges::sort(intervals);
        // NOTE: ans 的最后一个区间表示当前正在合并的区间
        vector<vector<int>> ans;

        // 比较 interval 的左端点与当前正在合并的区间右端点
        // 判断 interval 是否可以合并
        for (auto& interval : intervals) {
            // 不可以合并
            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            }
            // 可以合并
            else {
                // 是否更新合并区间右端点
                if (interval[1] > ans.back()[1]) {
                    ans.back()[1] = interval[1];
                }
            }
        }

        return ans;
    }
};
// @leet end

int main() { return 0; }
