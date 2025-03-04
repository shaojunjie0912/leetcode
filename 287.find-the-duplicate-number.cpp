#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 双指针
    // 相遇前: slow: 1 步, fast: 2 步
    // 相遇后: fast -> 初始位置, 1 步
    // 再相遇: 即重复的值, 返回
    // NOTE: 这里的步数通过: 索引的值更新
    // e.g.
    // nums:  1 3 4 2 2
    // index: 0 1 2 3 4
    // index(0) 值为 1, 因此下一步去 index(1)
    // index(1) 值为 3, 因此下一步去 index(3)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];        // 初始值就让它走一步
        int fast = nums[nums[0]];  // 初始值就让它走两步
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;  // HACK: 快指针回到初始位置(从索引 0 开始)
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
// @leet end

int main() {
    return 0;
}
