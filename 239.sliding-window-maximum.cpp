#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 双端队列中存放的是「索引」！

// @leet start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;  // 单调双端队列 (递减) 存放对应元素索引
        for (int i = 0; i < nums.size(); ++i) {
            // 1. 维护单调性
            // 如果入的值大于队列尾 q.back() 则队列一直弹出尾
            // 要维持队列单调递减
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);  // 把入的值加入队列尾

            // 2. 维护窗口有效性
            // 出
            // 如果队列首的索引不在窗口中了, 则队列首弹出
            if (i - q.front() + 1 > k) {
                q.pop_front();
            }

            // 3. 更新答案, 满足窗口大小才更新
            if (i < k - 1) {
                continue;
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
