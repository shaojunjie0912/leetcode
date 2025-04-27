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

// 前缀和
// s[0] = 0
// s[1] = a[0]
// s[2] = a[0] + a[1]
// ...
// s[i+1] = s[i] + a[i]
// sum(a[left]+...+a[right]) = s[right+1] - s[left]

// @leet start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        s.resize(n + 1);  // s[0] ~ s[n], 一共 n + 1 个
        s[0] = 0;
        for (int i = 0; i < n; ++i) {  // i + 1 < n + 1
            s[i + 1] = s[i] + nums[i];
        }
    }

    int sumRange(int left, int right) { return s[right + 1] - s[left]; }

private:
    // 前缀和数组 (s[0] = 0)
    vector<int> s;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @leet end

int main() { return 0; }
