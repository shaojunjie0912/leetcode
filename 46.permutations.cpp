#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 排列型回溯

// 「排列」区别于「组合」: 只要顺序不同就可以重选
// 所以选了一个数后, 可以用集合/数组告诉下面还可以选哪些数
// C++ 用 vector<int> on_path 假装 bool 数组

// @leet start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> path(n);     // 所有排列长度相同都是 n, 这里直接覆盖不需要恢复现场
        vector<int> on_path(n);  // 标记选的数字, 1 代表选了, 0 代表没选

        function<void(int)> dfs = [&](int i) -> void {
            // 边界: i == n
            if (i == n) {
                ans.push_back(path);
                return;
            }
            // 非边界: i < n
            // j 遍历 0 ~ n-1 因为排列可以重选, 只要顺序不同即可
            for (int j = 0; j < n; ++j) {
                if (!on_path[j]) {       // 只取还没被选的数字
                    path[i] = nums[j];   // 直接覆盖, NOTE: path[i] 和 nums[j]
                    on_path[j] = true;   // 标记
                    dfs(i + 1);          // 递归 >= i + 1
                    on_path[j] = false;  // 恢复现场
                }
            }
        };
        dfs(0);  // 递归入口
        return ans;
    }
};
// @leet end

int main() { return 0; }
