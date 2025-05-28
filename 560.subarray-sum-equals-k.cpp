#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 前缀和 + 哈希表
// 但这里计算答案数量, 而不是索引, 注意哈希表的值是出现次数计数

// 1. 前缀和: 子数组 [i, j] 的和 = pre_sum[j+1] - pre_sum[i] = k
// 2. 类比两数之和 (本题是两数之差 = k) NOTE: pre_sum - k !!
// 3. 哈希表: 向右枚举 pre_sum[j], 查询左边是否有 pre_sum[j] - k (用范围 for)

// @leet start
class Solution {
public:
    // 一次遍历 (同时计算前缀和 + 判断哈希表)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans{0};

        unordered_map<int, int> cnt;
        cnt[0] = 1;  // 初始值 (对应s[0]=0)

        int pre_sum{0};  // 前缀和 (单个变量, 这里 s[0]=0)
        for (auto x : nums) {
            pre_sum += x;
            if (cnt.contains(pre_sum - k)) {
                ans += cnt[pre_sum - k];  // NOTE: 不是 ++ 而是加 cnt
            }
            ++cnt[pre_sum];
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
