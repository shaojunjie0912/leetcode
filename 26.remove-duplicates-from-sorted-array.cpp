#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
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

// NOTE:
// 1. 非严格递增!!! 有顺序的!!
// 2. 想象成空位
// 3. 用赋值

// @leet start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int room{1};  // 第一个元素得保留, 因此空位从第二个开始
        // 空位移动条件: 跟前一个元素相同
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {  // NOTE: 比较 i 和 i - 1
                nums[room++] = nums[i];
            }
        }
        return room;
    }
};
// @leet end
