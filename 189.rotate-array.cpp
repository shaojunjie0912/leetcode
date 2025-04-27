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

// 首先: 所有 k >= n 的情况都可以转为 0 <= k < n 的情况
// 原: A + B
// 想要: B + A

// 操作:
// 1. 全部反转: rev(B) + rev(A)
// 2. 反转 B: rev(rev(B)) = B
// 3. 反转 A: rev(rev(A)) = A
// -> B + A

// @leet start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        ranges::reverse(nums);
        ranges::reverse(nums.begin(), nums.begin() + k);
        ranges::reverse(nums.begin() + k, nums.end());
    }
};
// @leet end

int main() { return 0; }
