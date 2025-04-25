#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
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
    int longestConsecutive(vector<int>& nums) {
        // NOTE: 要求 O(n), 不能排序 O(nlog(n))
        // nums 中元素放入哈希集合 unordered_set 中
        unordered_set<int> set{nums.begin(), nums.end()};
        int ans{0};
        for (auto x : set) {
            // 只有当 x 是起点 (即 x-1 不在 set 中) 时, 才往后找
            if (!set.contains(x - 1)) {
                int len = 1;
                int cur = x + 1;
                while (set.contains(cur)) {
                    ++len;
                    ++cur;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
