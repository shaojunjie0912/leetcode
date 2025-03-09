#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 定长滑动窗口
// 这道题一样可以将均值阈值转化为和阈值, 减少循环内计算均值

// @leet start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans{0};
        int curr_sum{0};
        int sum_thresh{threshold * k};         // mean阈值转化为sum阈值
        for (int i{0}; i < arr.size(); ++i) {  // 入
            curr_sum += arr[i];

            if (i < k - 1) {
                continue;
            }

            // 更新
            if (curr_sum >= sum_thresh) {
                ++ans;
            }

            // 出
            curr_sum -= arr[i - k + 1];
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
