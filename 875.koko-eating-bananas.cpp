#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 二分!
// HACK: 确定边界!
// 1 <= k <= max(piles), 在该范围寻找 target
// 由于 piles 堆数 <= h 小时数
// 因此右边界理解: 如果一小时能吃完一堆, 那么一定可以全部吃完

// 红色: check = false (左侧)
// 蓝色: check = true (右侧)

// @leet start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = ranges::max(piles);  // NOTE: max 是值, max_element 是迭代器
        auto check = [&](int k) -> bool {
            int64_t sum = 0;  // NOTE: 溢出
            for (auto& pile : piles) {
                sum += (pile + k - 1) / k;  // pile/k 向上取整
            }
            if (sum <= h) {
                return true;
            } else {
                return false;
            }
        };
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {  // 当前及右边是蓝色, 去左边
                r = mid - 1;
            } else {  // 当前及左边是红色, 去右边
                l = mid + 1;
            }
        }
        return l;
    }
};
// @leet end

int main() {
    return 0;
}
