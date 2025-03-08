#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 第一个 >= x 的位置 NOTE: 标准库算法返回 iterator
        return ranges::lower_bound(nums, target) - begin(nums);
    }
};
// @leet end

int main() {
    return 0;
}
