#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 「更新答案」和「出」两个步骤的顺序视情况而定

// NOTE: 队列中存放的是「索引」！

// 这里的「出」跟滑窗不太一样, 因为单调双端队列中存放的对应元素索引可能是乱序的

// @leet start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;  // 单调双端队列 (递减) 存放对应元素索引
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {  // HACK: 索引取值
                q.pop_back();
            }
            // 入
            q.push_back(i);

            // 出 (窗口往右滑, 左边是时候离开了, 如果 q.front() 正好是左边)
            if (i - q.front() >= k) {  // NOTE: 这里确实计算索引差值, 超过了 k 个
                q.pop_front();
            }
            // 更新答案
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
