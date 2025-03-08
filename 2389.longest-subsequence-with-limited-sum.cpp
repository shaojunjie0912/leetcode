#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE:
// 子序列: 不要求连续
// 子数组/子串: 要求连续

// @leet start
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // NOTE: 排序二分, 因为要和的数量尽可能多, 那么小的在前面最好
        ranges::sort(nums);
        // 遍历 queries 并原地修改 queries 作为结果
        // 思考变化: 本题求的是前多少个元素之和 >= queries[i] TODO: 前缀和?
        for (auto& q : queries) {
        }
        return queries;
    }
};
// @leet end

int main() {
    return 0;
}
