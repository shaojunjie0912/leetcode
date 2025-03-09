#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// HACK: C++
// DBL_MAX 是<正>double最大
// DBL_MIN 是<正>double最小
// 表示负double数最大: -DBL_MAX

// 定长滑动窗口
// NOTE: 思考: 平均数最大, 也就是和最大, 用和简单, 循环中少一个计算均值

// 如果使用平均数, 必须在第一个窗口形成之后再计算
// 即放在 i<k-1 continue 后

// @leet start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum{INT_MIN};  // NOTE: 元素可能为负数, 所以初始值用INT_MIN
        int curr_sum{0};
        for (int i{0}; i < nums.size(); ++i) {  // 入
            curr_sum += nums[i];

            if (i < k - 1) {  // 不足第一个窗口大小则进入下一次循环
                continue;
            }

            // 更新
            max_sum = max(max_sum, curr_sum);

            // 出
            curr_sum -= nums[i - k + 1];
        }
        return (double)max_sum / k;
    }

    // double findMaxAverage(vector<int>& nums, int k) {
    //     double max_mean{-DBL_MAX};
    //     double curr_mean{0.0};
    //     int curr_sum{0};
    //     for (int i{0}; i < nums.size(); ++i) {  // 入
    //         curr_sum += nums[i];

    //         if (i < k - 1) {
    //             continue;
    //         }
    //         curr_mean = (double)curr_sum / k;

    //         // 更新
    //         max_mean = max(max_mean, curr_mean);

    //         // 出
    //         curr_sum -= nums[i - k + 1];
    //     }
    //     return max_mean;
    // }
};
// @leet end

int main() {
    return 0;
}
