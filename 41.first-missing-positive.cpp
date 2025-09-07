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

// 「下标从 1 开始, 都是跟 i+1 比较」
// 座位编号: 1 ~ n
// 学号: 1 ~ n

// NOTE: 第一次遍历「交换座位」：只处理在范围内的
// NOTE: 第二次遍历「检查是否对应」
// 注意: "影分身"
// 忽略不在范围的学号

// 答案情况 1: 交换座位后第一个学号与座位编号不匹配的学生: 座位编号
// 答案情况 2: 所有学生都坐在正确座位上: n + 1

// @leet start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 一次遍历「交换座位」
        for (int i = 0; i < n; ++i) {
            // 如果 1. 元素值在范围内[1,n] 且 2. 真身不在正确座位
            // 则交换
            while (1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
            // 不在范围内 或 真身在正确座位, 直接跳过
        }

        // 二次遍历「检查是否对应」
        for (int i = 0; i < n; ++i) {
            if (i + 1 != nums[i]) {  // 座位编号 != 学号
                return i + 1;
            }
        }
        return n + 1;  // 都匹配则 n + 1
    }
};
// @leet end

int main() { return 0; }
