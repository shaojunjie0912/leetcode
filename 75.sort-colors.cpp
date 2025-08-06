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

// 插入排序? ❌️
// 插入元素后, 对比排序后的原数组和现数组, 只有固定位置元素变化
// ❌️ 不是「插入元素」
// ⭕️ 而是「修改元素」

// nums  = [0, 1, 1, 2, 2]
// nums' = [0, 0, 1, 1, 2, 2]
// 如果插入的元素是 0, 则算法:
// 1. 数组中 0 的个数: 记为 p0, 就是要改为 0 的位置, nums[p0] = 0
// 2. 数组中 0 和 1 的个数: 记为 p1, 就是要改为 1 的位置, nums[p1] = 1
// 3. 数组末尾新增的位置: 记为 i, 把 nums[i] = 2

// NOTE: 考虑到数组中可能没有 2, 因此反向执行上面流程
// 第 3 步肯定要走, 反过来被覆盖就没影响了

// 如果插入的元素是 1, 则算法:
// 跳过上面第 1 步

// 如果插入的元素是 2, 则算法:
// 跳过上面第 1 和 2 步

// @leet start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0{0}, p1{0};
        for (int i = 0; i < nums.size(); ++i) {
            // NOTE: 一定要先保存, 不然被下面修改了, 判断的都是 x 不是 i
            int x = nums[i];
            nums[i] = 2;   // 执行这一步的有: 插入 0, 1, 2
            if (x <= 1) {  // 执行这一步的有: 插入 0, 1
                nums[p1++] = 1;
            }
            if (x == 0) {  // 执行这一步的有: 插入 0
                nums[p0++] = 0;
            }
        }
    }
};
// @leet end
