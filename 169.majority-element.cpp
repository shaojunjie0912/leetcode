#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
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

// 我们维护一个候选人 candidate 和一个计数器 count。初始时，candidate 可以是任意值，count 为 0。
// 我们遍历数组 nums 中的每一个元素 num。
// 当遍历时：

// 如果 count 为 0，我们将当前的 num 设为新的 candidate，并将 count 设为 1。
// 这意味着前一阶段的战斗已经结束，我们从当前元素开始寻找新的候选人。

// 如果 num 与 candidate 相同，我们就将 count 加 1。这表示我们的候选人又获得了一票支持。

// 如果 num 与 candidate 不同，我们就将 count 减 1。
// 这表示我们的候选人与其他候选人进行了一次“消耗”，抵消掉了。

// 由于多数元素比所有其他元素的总和还要多，它在经过所有的消耗后，其 count 值必然大于0。
// 因此，遍历结束后，留下的 candidate 就是我们要找的多数元素。

// @leet start
class Solution {
public:
    // 摩尔投票 O(n) + O(1)
    int majorityElement(vector<int>& nums) {
        int candidate{0};
        int cnt{0};
        for (auto& x : nums) {
            if (cnt == 0) {
                candidate = x;
                cnt = 1;  // 这里是重置为 1, 开启新一轮选举
            } else {
                if (candidate == x) {
                    ++cnt;  // 支持 + 1
                } else {
                    --cnt;  // 不支持 - 1
                }
            }
        }
        return candidate;
    }
};
// @leet end
