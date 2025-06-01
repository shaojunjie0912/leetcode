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

// @leet start
class Solution {
public:
#if 1
    // 摩尔投票 O(n) + O(1)
    int majorityElement(vector<int>& nums) {
        int candidate{0};
        int cnt{0};
        for (auto& x : nums) {
            if (cnt == 0) {
                candidate = x;
                cnt = 1;
            } else {
                if (candidate == x) {
                    ++cnt;  // 支持 + 1
                } else {
                    --cnt;  // 不支持 - 1
                }
            }
        }
        return candidate;
    }
#else
    // 哈希 O(n) + O(n)
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (auto& x : nums) {
            ++cnt[x];
            if (cnt[x] > n / 2) {
                return x;
            }
        }
        return -1;
    }
#endif
};
// @leet end
