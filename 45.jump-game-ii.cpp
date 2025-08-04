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
    int jump(vector<int> &nums) {
        int n = nums.size();
        int ans{0};
        int curr_right{0};                 // 当前桥的右端点
        int next_right_max{0};             // 下一座桥右端点最大值
        for (int i = 0; i < n - 1; ++i) {  // NOTE: < n - 1 即到 n - 2 这边就建桥了
            // 记录下一座桥最大端点
            next_right_max = max(next_right_max, i + nums[i]);
            // 如果无路可走必须建桥
            if (i == curr_right) {
                curr_right = next_right_max;  // curr 到 next_max 这边
                ++ans;                        // 建桥数量 + 1
            }
        }
        return ans;
    }
};
// @leet end
