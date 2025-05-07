#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 排列型回溯: 枚举选哪个

// 全排列区别于组合: 只要顺序不同, 就可以重选并且代表不同排列
// 所以选了一个数后, 可以用集合/数组告诉下面还可以选哪些数
// 但是 C++ 集合没有 Python 好用

// j 循环里面有一个 dfs 是 i + 1, 跟之前不一样, 感觉是跟 path 中 i 一样k

// @leet start
class Solution {
public:
    // on_path 写法, 更通用
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> path(n);     // 所有排列长度相同, 都是 n, 这里直接覆盖不需要恢复现场
        vector<int> on_path(n);  // 记录选了哪些数字

        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            // 排列可以重选的, 只要顺序不同即可, 所以 j 从 0 而不是 i
            for (int j = 0; j < n; ++j) {
                if (!on_path[j]) {       // 只取还没被选的数字
                    path[i] = nums[j];   // 直接覆盖, 注意这里是 path[i] 和 nums[j]
                    on_path[j] = true;   // 标记为已经选上
                    dfs(i + 1);          // NOTE: 这里 dfs 是 i + 1, 难道跟 path 中的 i 对应?
                    on_path[j] = false;  // 恢复现场
                }
            }
        };

        dfs(0);
        return ans;
    }
};
// @leet end

int main() { return 0; }
