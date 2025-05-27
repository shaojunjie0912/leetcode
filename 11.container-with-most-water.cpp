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
        int ans{0};
        int n = height.size();
        int l{0}, r{n - 1};
        while (l < r) {
            int area = (r - l) * min(height[l], height[r]);
            ans = max(ans, area);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
