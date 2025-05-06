#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 子集型回溯
// - 输入角度
// - 答案角度

// @leet start
class Solution {
public:
#if 0
    // 输入角度: 枚举第 i 个数选或不选
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;  // NOTE: 跟电话号码不一样, 没有初始大小
        int n = nums.size();
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            // 枚举第 i 个数选
            path.push_back(nums[i]);
            dfs(i + 1);       // 构造 >= i + 1
            path.pop_back();  // 恢复现场

            // 枚举第 i 个数不选
            dfs(i + 1);  // 构造 >= i + 1
        };
        dfs(0);
        return ans;
    }
#else
    // 答案角度: 枚举第 i 个数选哪一个
    // 要求不能有重复子集, 所以 dfs(j+1)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();

        // dfs(i) 的 i 表示现在要枚举选 nums[i] 到 nums[n-1] 中的一个数
        function<void(int)> dfs = [&](int i) -> void {
            // 不需要边界条件 i==n return 因为当 i==n 时不会进入循环
            ans.push_back(path);  // 每个节点都是答案

            // 用 j 遍历 i 到 n - 1
            for (int j = i; j < n; ++j) {  // 枚举选哪一个
                path.push_back(nums[j]);   //
                dfs(j + 1);                // 遍历剩下的 j + 1 到 n - 1
                path.pop_back();           // 恢复现场
            }
        };

        dfs(0);
        return ans;
    }
#endif
};
// @leet end

int main() { return 0; }
