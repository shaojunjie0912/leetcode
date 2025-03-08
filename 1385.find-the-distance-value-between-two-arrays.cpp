#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // NOTE: 审题: !!<不存在>!!
        // 所以如果存在 arr1[i] - d  <= arr2[j] <= arr1[i] + d 直接跳过

        int ans{0};
        // 排序 arr2
        ranges::sort(arr2);
        // 遍历 arr1
        for (auto& num : arr1) {
            int lower = num - d;
            int upper = num + d;
            // 存在 lower <= arr2[j] <= upper 直接跳过
            auto first{ranges::lower_bound(arr2, lower)};
            // 最后一个 <= upper: 第一个 ( > upper) 左边
            auto last{ranges::upper_bound(arr2, upper) - 1};
            // HACK: 这里条件自己想了挺久
            // 其实就是 [lower, upper] 区间内如果存在元素, 则跳过
            if (first <= last) {  // NOTE: first<=last
                continue;
            }
            ++ans;
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
