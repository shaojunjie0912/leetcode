#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int search(vector<int> &nums, int target) {
#if 0
        // 左闭右开区间 [ , size)
        int left = 0;
        int right = nums.size();  // HACK: ! size() !
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                return mid;
            }
        }
#else
        // 左闭右闭区间 [ , size - 1]
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return -1;
#endif
    }
};
// @leet end

int main() {
    return 0;
}
