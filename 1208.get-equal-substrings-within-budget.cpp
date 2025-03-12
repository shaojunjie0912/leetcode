#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 不定长滑动窗口

// @leet start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans{0};
        int curr_cost{0};
        for (int l{0}, r{0}; r < s.size(); ++r) {
            curr_cost += std::abs(s[r] - t[r]);
            while (curr_cost > maxCost) {
                curr_cost -= std::abs(s[l] - t[l]);
                ++l;
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
