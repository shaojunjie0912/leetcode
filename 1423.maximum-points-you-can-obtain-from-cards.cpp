#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 逆向思维: 滑动窗口
// k 张和 + 剩余和 = 总和(固定)
// 即求剩余和最小, 而每次都是从两边拿, 因此中间连续可用滑窗

// @leet start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_sum{std::accumulate(begin(cardPoints), end(cardPoints), 0)};
        int min_rest_sum{INT_MAX};          // 剩余牌最小总和
        int curr_rest_sum{0};               // 剩余牌当前总和
        int new_k = cardPoints.size() - k;  // 窗口大小(NOTE: 本题k<=n, 因此可能造成窗口大小为0)
        if (new_k == 0) {                   // 窗口大小为0提前返回
            return total_sum;
        }
        for (int i = 0; i < cardPoints.size(); ++i) {
            // 入
            curr_rest_sum += cardPoints[i];
            if (i < new_k - 1) {
                continue;
            }
            // 更新
            min_rest_sum = min(min_rest_sum, curr_rest_sum);
            // 出
            curr_rest_sum -= cardPoints[i - new_k + 1];
        }
        return total_sum - min_rest_sum;
    }
};
// @leet end

int main() {
    return 0;
}
