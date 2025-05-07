#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 只要方案数量

// @leet start
class Solution {
public:
    int totalNQueens(int n) {
        int ans{0};
        vector<int> on_col(n);
        vector<int> diag_sum(2 * n - 1);
        vector<int> diag_diff(2 * n - 1);

        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                ++ans;
                return;
            }
            for (int c = 0; c < n; ++c) {
                int rc_sum = r + c;
                int rc_diff = r - c + n - 1;
                if (!on_col[c] && !diag_sum[rc_sum] && !diag_diff[rc_diff]) {
                    on_col[c] = diag_sum[rc_sum] = diag_diff[rc_diff] = true;
                    dfs(r + 1);
                    on_col[c] = diag_sum[rc_sum] = diag_diff[rc_diff] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @leet end

int main() { return 0; }
