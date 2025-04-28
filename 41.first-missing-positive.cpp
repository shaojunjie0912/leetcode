#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 「下标从 1 开始」
// 座位编号: 1 ~ n
// 学号: 1 ~ n

// 一次遍历「交换座位」+ 二次遍历「检查是否对应」
// 答案情况 1: 交换座位后第一个学号与座位编号不匹配的学生: 座位编号
// 答案情况 2: 所有学生都坐在正确座位上: n + 1

// @leet start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // [1, 1]
        // 一次遍历「交换座位」
        for (int i = 0; i < n; ++i) {
            // while 循环交换当前位置
            while (i + 1 != nums[i]) {
                // 如果不是要求的正整数或重复元素(对应位置已经有一个正确学生了)
                // break 打破循环
                // 否则如果数组有重复元素 [1, 1] 则 while 和 swap 会导致死循环
                if (nums[i] < 1 || nums[i] > n || nums[nums[i] - 1] == nums[i]) {
                    break;
                }
                // 学号 != 座位编号
                // 交换当前座位学生和正确的座位编号学生
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        int ans{n + 1};
        // 二次遍历「检查是否对应」
        for (int i = 0; i < n; ++i) {
            if (i + 1 != nums[i]) {  // 座位编号 != 学号
                return i + 1;
            }
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
