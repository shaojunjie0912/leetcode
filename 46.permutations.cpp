#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// Q: 什么时候需要恢复现场?
// A: 假设存在递归函数 f
// 想从当前状态做出决策变为其他状态, 做出第二次决策前, 需要恢复原状态
// NOTE: 这里的状态是递归函数的形参, 且能够被每层递归函数修改
// 因此需要恢复, 如果按值传递, 则每层都是深拷贝, 独立的状态, 不需要恢复
//            状态0
//      ↓↑      ↓↑      ↓↑
//      A       B       C
//      ↓↑      ↓↑      ↓↑
//   状态1     状态2    状态3

// TODO: 递归的最外层: 让每个数来 0 的位置, 再对后面递归
// 思考:
// i = 0 时, 对 i + 1 进行递归: 控制每个数来 1 的位置...
// i = 1 时, 对 i + 1 进行递归: 控制每个数来 2 的位置...
// ...
// HACK: 重要!!恢复现场!! 递归完成后, 交换回原来的位置
// 否则会有重复的结果

// @leet start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        R(nums, 0, ans);
        return ans;
    }

    // nums 按引用传递的状态, 可直接被每层递归修改, 因此需要恢复现场
    // HACK: 这里不用 path 了, 直接用 nums, 原地修改
    // i 为 nums 的索引
    // ans 保存结果
    void R(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        // NOTE: j 是每层递归从 i 开始往后走的索引
        // 初始值 j = i
        for (int j = i; j < nums.size(); ++j) {
            std::swap(nums[i], nums[j]);
            R(nums, i + 1, ans);
            std::swap(nums[j], nums[i]);
        }
        return;
    }
};
// @leet end

int main() {
    return 0;
}
