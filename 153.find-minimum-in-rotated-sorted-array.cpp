#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 二分(NOTE: 跟 nums[n-1] 即数组最右边的数比较 )
// NOTE: 以下的左/右侧是当前反转后顺序情况
// 红色: 最小值左侧
// 蓝色: 最小值及其右侧

// x > nums[n-1]:
// - [4, x, 6, ..., 0, 1] x 在最小值左侧

// x <= nums[n-1]:
// - [4, 5, 6, ..., 9, x] x 就是最小值
// - [4, ..., 0, 1, 2, x] x 在最小值右侧

// @leet start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 最后一个数一定是蓝色(就是最小值或在最小值右侧)
        // HACK: 如果最后一个数就是最小值, 则 l 最后会来到 n-1 位置
        // 即一开始 r(n-2) 的右侧一个
        // 这里同样如果 r 一开始为 n-1, 则最后 l 越界
        int l = 0;
        int r = nums.size() - 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums.back()) {  // mid 在最小值左侧, 需要往右找
                l = mid + 1;
            } else {  // mid 在最小值右侧, 需要往左找
                r = mid - 1;
            }
        }
        return nums[l];  // NOTE: 注意最后返回最小值而不是索引
    }
};
// @leet end

int main() {
    return 0;
}
