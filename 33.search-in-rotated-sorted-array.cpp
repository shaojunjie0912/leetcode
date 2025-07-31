#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 闭区间 [0, n-2] 二分, 跟最右侧一个元素 nums[n-1] 比较大小判断递增段

// NOTE: 1. 判断递增段 2. 判断红蓝的条件必须是完整的逻辑二分!!
// NOTE: nums[m] 一定用 < target 或 >= target 判断!
// NOTE: [第一段, 第二段] 一定是 > end 以及 <= end !

// 红色: nums[mid] 在 target 左侧
// 蓝色: nums[mid] 就是 target 或在 target 右侧

// @leet start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int end = nums[n - 1];

        // 判断 x = nums[mid] 是否在 target 左侧
        auto on_left = [&](int mid) -> bool {
            int x = nums[mid];
            if (x > end) {  // x 在第一段
                // 要想 x 在 target 左侧, 要么 target 也在第一段且 > x, 要么 target 在第二段
                // NOTE: <= end
                return x < target || target <= end;
            } else {  // x 在第二段
                // 要想 x 在 target 左侧, 必须 target 也在第二段, 且 x < target
                // NOTE: <= end
                return target <= end && x < target;
            }
        };

        int l = 0, r = n - 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (on_left(mid)) {  // num[mid] 在 target 左侧, 因此往右找 target
                l = mid + 1;
            } else {  // num[mid] 在 target 右侧, 因此往左找 target
                r = mid - 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
// @leet end

int main() { return 0; }
