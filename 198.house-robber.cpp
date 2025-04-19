#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 递推
// f[i] = max(f[i-1], f[i-2] + nums[i])
// f[i+2] = max(f[i+1], f[i] + nums[i])

// @leet start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0;  // 上上个
        int f1 = 0;  // 上个
        int new_f;
        for (int i = 0; i < n; ++i) {
            new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};
// @leet end

int main() { return 0; }
