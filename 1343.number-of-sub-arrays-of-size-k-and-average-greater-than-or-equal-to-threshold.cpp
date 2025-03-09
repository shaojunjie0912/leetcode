#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 定长滑动窗口
// 这道题同理, 当第一个窗口还没形成, 就无法比较

// @leet start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans{0};
        int curr_sum{0};
        for (int i{0}; i < arr.size(); ++i) {  // 入
            curr_sum += arr[i];
            curr_mean = curr_sum / k;

            if (i < k - 1) {
                continue;
            }

            // 更新

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
