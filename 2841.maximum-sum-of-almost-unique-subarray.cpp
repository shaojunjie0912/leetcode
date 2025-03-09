#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 强化记忆: 子数组和子串都必须连续, 子序列不需要

// 定长滑动窗口
// 这题增加了一个几乎唯一限定, 用哈希表

// int diff{0};// 当前窗口不同元素个数 // NOTE: 不要 diff, 通过map大小判断

// @leet start
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> curr_map;
        int64_t max_sum{0};  // 因为nums[i]>=1
        int64_t curr_sum{0};
        for (int i = 0; i < nums.size(); ++i) {  // 右边界入
            int right{nums[i]};
            curr_sum += right;
            ++curr_map[right];  // HACK: 一行搞定下面多行
            // if (curr_map.contains(right)) {
            //     ++curr_map[right];
            // } else {
            //     curr_map[right] = 1;
            // }

            if (i < k - 1) {
                continue;
            }

            // 满足几乎唯一子数组条件才更新
            if (curr_map.size() >= m) {  // HACK: 通过map大小判断
                // 更新
                max_sum = max(max_sum, curr_sum);
            }

            // 左边界出
            int left{nums[i - k + 1]};
            curr_sum -= left;

            // HACK: 一行搞定下面多行
            if (--curr_map[left] == 0) {  // 如果原来就是1那就直接删除
                curr_map.erase(left);
            }

            // NOTE: 傻孩子, 还是不了解map, 一行搞定
            // if (curr_map[left] > 1) {
            //     --curr_map[left];
            // } else {
            //     curr_map.erase(left);
            // }
        }
        return max_sum;
    }
};
// @leet end

int main() {
    return 0;
}
