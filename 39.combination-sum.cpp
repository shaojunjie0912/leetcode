#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 区别于固定个数 k 的组合型回溯
// 这里没有 k 的个数限制, 只有目标和限制

// NOTE: 同一个数字可以无限制重复被选取

// @leet start
class Solution {
public:
#if 1
    // 输入角度: 选/不选
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&](int i, int t) -> void {

        };

        dfs() return ans;
    }
#else
// 答案角度: 枚举选哪个
#endif
};
// @leet end

int main() { return 0; }
