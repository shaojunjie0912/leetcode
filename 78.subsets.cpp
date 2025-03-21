#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        // 枚举第 i 个选/不选
        auto dfs = [&](auto&& self, int i) {
            if (i == n) {
                return;
            }
        };
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
