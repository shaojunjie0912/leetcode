#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 双指针
// 中间的垂线与高度小的垂线组合一定水量更小
// 因此不能包含高度小的垂线, 谁小就移动谁

// @leet start
class Solution {
public:
    // left right 谁小, 以谁为边界开始结算, 然后小的往中间移动
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans{0};
        while (left < right) {
            int area = (right - left) * std::min(height[right], height[left]);
            ans = max(ans, area);
            // 小的往中间移动
            if (height[left] > height[right]) {
                --right;
            } else {
                ++left;
            }
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
