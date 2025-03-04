#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 双指针, 直接记
    // left right 谁小, 以谁为边界开始结算, 然后小的往中间移动
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int h = 0;
        while (left < right) {
            h = min(height[left], height[right]);
            ans = max(ans, h * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
