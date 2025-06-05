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

// NOTE: (k 取余)
// 1. 反转整个数组
// 2. 反转前 k 个
// 3. 反转后 n - k 个

// @leet start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto reverse = [&](vector<int>& nums, int l, int r) -> void {
            while (l < r) {
                std::swap(nums[l++], nums[r--]);
            }
        };
        int n = nums.size();
        k %= n;                   // NOTE: k 取余循环!!
        reverse(nums, 0, n - 1);  // 反转整个数组
        reverse(nums, 0, k - 1);  // 反转前 k 个
        reverse(nums, k, n - 1);  // 反转后 n - k 个
    }
};
// @leet end

int main() { return 0; }
