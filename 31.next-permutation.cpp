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

// 算法:
// * 从后(n-2)向前找第一个升序对(nums[i], nums[i+1])的较小数即 nums[i] < nums[i+1] 的索引 i
// 这个 nums[i] 就是我们要操作的“较小数”
// 如果找不到这样的 i, 即整个数组是降序的, 如 [3, 2, 1]，说明这已经是最大的排列。
// 根据题意，下一个排列是最小的排列，所以直接将整个数组反转，然后结束。

// * 如果找到了 i，再从后向前扫描，找到第一个满足 nums[j] > nums[i] 的索引 j。
// 这个 nums[j] 就是我们要找的“较大数”。

// * 交换: 较小数 nums[i] 和较大数 nums[j]

// * 反转: 从索引 i+1 到数组末尾的部分 NOTE: 反转是为了让后面变最小

// @leet start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // 从后向前找第一个升序对, 这个 nums[i] 就是要操作的较小数
        int i = n - 2;  // 因为是找「对」所以从 n - 2 开始
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) {  // 没有较小数, 完全逆序, 下一个排列重新开始
            ranges::reverse(nums);
            return;  // 直接返回
        }
        // 从后向前找第一个 nums[j] > nums[i], 这个nums[j]就是较大数
        int j = n - 1;  // 从 n - 1 开始
        while (j > i && nums[j] <= nums[i]) {
            --j;
        }
        // 交换
        std::swap(nums[i], nums[j]);
        // 如果 i<0 或步骤四: 反转 i 之后的部分(>=i+1)
        ranges::reverse(nums.begin() + i + 1, nums.end());
    }
};
// @leet end

// ------------------------------------------------------------
// --------------------------- 分析 ---------------------------
// ------------------------------------------------------------

// 要找到一个排列的“下一个”字典序更大的排列，关键在于进行一次“尽可能小”的增操作。

// 考虑一个排列，例如 [1, 2, 7, 4, 3, 1]。

// 我们希望改变哪个位置的数字？
// 为了让排列的增幅尽可能小，我们应该尽可能地改变右边（低位）的数字。

// 如何改变？
// 我们从右向左观察，序列 [7, 4, 3, 1] 是一个降序序列，
// 已经是其自身能构成的最大排列了。再往左，我们遇到了 2。因为 2 < 7，
// 我们找到了一个“升序对” (2, 7)。 这意味着，如果我们把 2 换成一个比它大的数，
// 就能得到一个更大的排列。这个 2 就是我们要操作的“较小数”。

// 用什么数字来替换？
// 我们应该用 2 右边所有数字中，比 2 大的数里“最小”的那个数来替换它。这样能保证增幅最小。
// 在 [7, 4, 3, 1] 中，这个数是 3。这个 3 就是我们要找的“较大数”。

// 替换后做什么？
// 交换 2 和 3 后，排列变为 [1, 3, 7, 4, 2, 1]。此时，前缀 [1, 3]
// 已经确定了。为了得到字典序的“下一个”， 后缀 [7, 4, 2, 1]
// 必须是所有可能组合中最小的。由于这个后缀在交换前是降序的（交换后仍然保持降序特性），
// 我们只需将其反转，就能得到升序的最小排列 [1, 2, 4, 7]。

// 最终，我们就得到了下一个排列 [1, 3, 1, 2, 4, 7]。
