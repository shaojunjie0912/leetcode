#include <bits/stdc++.h>

#include <algorithm>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE: 四数之和 -> 三数之和 -> 两数之和
// NOTE: 4 数之和 = target 而不是 0!!!
// NOTE: 本题值都很大, 还是先把x y 变成int64_t, 看到 10^9 了, 且要相加

// @leet start
class Solution {
public:
    // i j k t?
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // NOTE: 啊啊啊啊忘记排序了
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i{0}; i < n - 3; ++i) {
            int64_t x = nums[i];
            if (i > 0 && x == nums[i - 1]) {  // NOTE: 是 if !!!!写错成 while 了
                continue;
            }
            // ============= 优化 =============
            if (x + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if (x + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }

            for (int j{i + 1}; j < n - 2; ++j) {
                int64_t y = nums[j];
                // NOTE: 这里遇到 [2,2,2,2,2] 时被跳过
                // !!条件j > i+1 !!!不是 j > 1
                if (j > i + 1 && y == nums[j - 1]) {  // NOTE: 是 if !!!!写错成 while 了
                    continue;
                }
                // ============= 优化 =============
                if (x + y + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if (x + y + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }
                int k{j + 1};
                int t{n - 1};
                while (k < t) {  // NOTE: 别忘了 while
                    // 接下来是两数之和逻辑
                    int64_t sum{x + y + nums[k] + nums[t]};
                    if (sum > target) {
                        --t;
                    } else if (sum < target) {
                        ++k;
                    } else {
                        // NOTE: 这里哪怕符合条件 k 和 t 还要继续往中间移动的
                        // 不能break!!, 还没遍历完呢
                        ans.push_back({(int)x, (int)y, nums[k], nums[t]});
                        // 往中间移动时, 跳过重复
                        ++k;
                        while (k < t && nums[k] == nums[k - 1]) {
                            ++k;
                        }
                        --t;
                        while (k < t && nums[t] == nums[t + 1]) {
                            --t;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @leet end

int main() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target{0};
    auto ans{Solution{}.fourSum(nums, target)};
    for (auto& v : ans) {
        cout << "[";
        for (auto& n : v) {
            cout << n << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
