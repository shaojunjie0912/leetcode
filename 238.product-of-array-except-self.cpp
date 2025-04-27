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

// 前后缀分解
// 不包含自身, 因此长度还是 n, 跟一般的前缀数组不一样哈
// 前缀乘积数组 pre
// 后缀乘积数组 suf

// @leet start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // 计算前缀乘积数组 (乘积不包含自身)
        vector<int> pre(n);
        pre[0] = 1;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        // 计算后缀乘积数组 (乘积不包含自身)
        vector<int> suf(n);
        suf[n - 1] = 1;
        for (int j = n - 2; j >= 0; --j) {
            suf[j] = suf[j + 1] * nums[j + 1];
        }

        vector<int> ans(n);
        for (int k = 0; k < n; ++k) {
            ans[k] = pre[k] * suf[k];
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
