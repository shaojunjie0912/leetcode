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

// 1. 数组 -> 无序集合(unordered_set)
// 2. 往后找 x + 1, x + 2... 在不在集合
// 3. x 是起点 (x-1 不在集合中) 才往后找

// @leet start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // NOTE: 要求 O(n), 不能排序 O(nlog(n))
        // nums 中元素放入集合中
        unordered_set<int> set{nums.begin(), nums.end()};
        int ans{0};
        // 数组中可能有重复元素, 因此应该遍历集合
        for (auto x : set) {
            // 只有当 x 是起点 (即 x-1 不在 set 中) 时, 才往后找
            if (!set.contains(x - 1)) {  // NOTE: 这里是 if !!
                int len = 1;
                while (set.contains(x + 1)) {
                    ++len;
                    ++x;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
