#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
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
// 非递减!!
// 从右往左覆盖

// @leet start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1{m - 1}, p2{n - 1}, p3{m + n - 1};
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p3--] = nums1[p1--];
            }
            // NOTE: 当 p1 < 0 时直接将 nums2 覆盖到 nums1 中
            else {
                nums1[p3--] = nums2[p2--];
            }
        }
    }
};
// @leet end
