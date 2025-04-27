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

// NOTE:
// 1. 前缀和: 子数组 [i, j] 的和 = s[j+1] - s[i] = k
// 2. 类比两数之和 (本题是两数之差 = target)
// 3. 哈希表: 向右枚举 s[j], 查询左边是否有 target - s[j]

// DEPRECATED:
// 本来我是用一个 set, 以为只要出现过答案就 +1
// 但是应该做 (前缀和, 次数) 这样的键值对映射
// 因为前缀可能存在重复, 某个前缀和可能会出现多次
// 但你 set 就只能去重保存一份, 所以漏掉了几个子数组的左边界

// @leet start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // 前缀和数组
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int ans{0};
        // 哈希表 (前缀和, 出现次数)
        unordered_map<int, int> cnt;
        // sum(nums[i]...nums[j]) = s[j+1] - s[i] = k
        // 遍历 s[j] 查询左侧是否有 s[j] - k
        for (auto sj : s) {  // 直接用范围for遍历, 不需要索引
            if (cnt.contains(sj - k)) {
                ans += cnt[sj - k];
            }
            ++cnt[sj];
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
