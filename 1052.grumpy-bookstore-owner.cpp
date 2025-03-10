#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 定长滑动窗口

// @leet start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int max_sum{0};
        // 原始所有不生气时间*对应顾客数量
        int total_sum{0};
        // NOTE: 不能用点积inner_product, 因为 0 不生气才乘, 1 生气反而不乘
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                total_sum += customers[i];
            }
        }

        int curr_sum{total_sum};  // curr_sum 初始值 total_sum
        for (int i = 0; i < customers.size(); ++i) {
            // ========== 入 ==========

            // 如果本来就没生气, 则窗口不对其更改, 满意数不变
            // 如果生气了, 则这里窗口将其改为不生气, 满意数增加
            if (grumpy[i] == 1) {
                curr_sum += customers[i];
            }

            if (i < minutes - 1) {
                continue;
            }

            // ========== 更新 ==========
            max_sum = max(max_sum, curr_sum);

            // ========== 出 ==========
            // NOTE: !! 如果左边界之前是生气的才移除,
            // 因为这是右边界在生气时才更改增加的
            // HACK: 最后求的是总和
            // 如果不生气时也移除, 那总和就不对了
            if (grumpy[i - minutes + 1] == 1) {
                curr_sum -= customers[i - minutes + 1];
            }
        }

        return max_sum;
    }
};
// @leet end

int main() {
    vector<int> customers{3, 2, 5};
    vector<int> grumpy{1, 1, 1};
    int minutes{3};
    cout << Solution{}.maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}
