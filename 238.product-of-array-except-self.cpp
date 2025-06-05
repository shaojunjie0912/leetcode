#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
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

// NOTE: 重点: 不算自身
// pre[i]: nums[0] ~ nums[i-1] 乘积
// suff[i]: nums[i+1] ~ nums[n-1] 乘积

// @leet start
class Solution {
public:
#if 1
    // 优化: 只计算 suff_multi, 后面计算 pre_multi 时更新 suff_multi
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff_multi(n, 1);
        // 后缀乘积
        suff_multi[n - 1] = 1;
        for (int j = n - 2; j >= 0; --j) {
            suff_multi[j] = suff_multi[j + 1] * nums[j + 1];
        }
        // 计算前缀乘积并更新答案(即 suff_multi)
        int pre_multi = 1;
        for (int k = 0; k < n; ++k) {
            suff_multi[k] *= pre_multi;
            pre_multi *= nums[k];  // 这里给下一次用
        }
        return suff_multi;
    }
#else
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_multi(n, 1);
        vector<int> suff_multi(n, 1);
        // 前缀乘积
        pre_multi[0] = 1;  // 其实不要写了
        for (int i = 1; i < n; ++i) {
            pre_multi[i] = pre_multi[i - 1] * nums[i - 1];
        }
        // 后缀乘积
        suff_multi[n - 1] = 1;
        for (int j = n - 2; j >= 0; --j) {
            suff_multi[j] = suff_multi[j + 1] * nums[j + 1];
        }
        // 计算 ans
        vector<int> ans(n);
        for (int k = 0; k < n; ++k) {
            ans[k] = pre_multi[k] * suff_multi[k];
        }
        return ans;
    }
#endif
};
// @leet end

int main() { return 0; }
