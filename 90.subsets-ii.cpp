#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
// 之前跟着左神写的, 但是时间复杂度不好
// 但是 java 正常, 可能 c++ 某些不是很好
class Solution {
public:
    // NOTE: 这道题是求组合!!(不关注顺序)
    //  111 222 333 444 ...
    // [   ]
    // 递归角度: 看第一组111 和剩下的 222 333 444 ...
    // 第一组取 0 个 1, 剩下别的组递归
    // 第一组取 1 个 1, 剩下别的组递归
    // 第一组取 2 个 1, 剩下别的组递归
    // 第一组取 3 个 1, 剩下别的组递归
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path(nums.size());  // 预分配空间
        // NOTE: 先排序, 让相同的组在一起
        sort(nums.begin(), nums.end());
        R(nums, 0, path, 0, ans);  // 一开始size为0
        return ans;
    }

    // 递归函数
    // size 控制 path 大小, 即要写入的位置
    void R(vector<int>& nums, int i, vector<int>& path, int size, vector<vector<int>>& ans) {
        // path 控制第一组要多少个 x
        if (i == nums.size()) {  // 到达数组末尾
            ans.emplace_back(path.begin(), path.begin() + size);
            return;
        }
        // 找到下一组第一个数的位置 j
        int j = i + 1;
        while (j < nums.size() && nums[i] == nums[j]) {
            ++j;
        }
        // HACK: 注意递归传入了 j 而不是 i
        // 第一组xxx..., 要 0,1,2... 个 x
        R(nums, j, path, size, ans);  // 要 0 个 x NOTE: 即path不增加,还是原来size
        while (i < j) {
            path[size++] = nums[i];  // 要 1,2...个x NOTE: 推入 path
            R(nums, j, path, size, ans);
            ++i;
        }
    }
};

class Solution1 {
public:
    // TODO: ChatGPT
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());  // 排序以便去重
        dfs(nums, 0, path, ans);
        return ans;
    }

    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);  // 直接存当前子集

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;  // 跳过重复元素

            path.push_back(nums[i]);      // 选当前元素
            dfs(nums, i + 1, path, ans);  // 递归搜索
            path.pop_back();              // TODO: 回溯
        }
    }
};
// @leet end

int main() {
    vector<int> nums{1, 1, 2};
    auto res{Solution().subsetsWithDup(nums)};
    return 0;
}
