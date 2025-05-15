#include <algorithm>
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

// 枚举选哪个
// dfs(i): 以 nums[i] 结尾的最长递增子序列 LIS 的长度
// dfs(i) = max{dfs(j)}

// @leet start
class Solution {
    enum Method {
        DFS_MEMO,
        DP_F,
    };

public:
    int lengthOfLIS(vector<int>& nums) {
        Method method{DFS_MEMO};
        switch (method) {
            case DFS_MEMO: {
                return SolveDfsMemo(nums);
            }
            case DP_F: {
                return SolveDpF(nums);
            }
        }
    }

private:
    // dfs(i) = max{dfs(j)} + 1, j < i && nums[j] < nums[i]
    int SolveDfsMemo(vector<int>& nums) {
        int n = nums.size();
        vector memo(n, -1);  // 记忆数组
        function<int(int)> dfs = [&](int i) -> int {
            // NOTE: 没有写边界条件, 因为如果 i = 0 循环不会执行
            int res{0};
            for (int j = 0; j < i; ++j) {  // 枚举「严格」小于 i 的 j
                if (nums[j] < nums[i]) {   // 如果 nums[j] < nums[i] 则继续递归
                    if (memo[j] == -1) {
                        memo[j] = dfs(j);
                    }
                    res = max(res, memo[j]);
                }
            }
            return res + 1;  // +1 表示 i
        };
        int ans{0};
        for (int i = 0; i < n; ++i) {  // 遍历整个数组递归
            ans = max(ans, dfs(i));
        }
        return ans;
    }

    // f[i] = max{f[j]} + 1, j < i && nums[j] < nums[i]
    // 思考: f 数组存储了 i 从 0 ~ n-1 时的 LIS 长度, 别用 res, ans 了
    // 关注 f 数组
    int SolveDpF(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        // 这里别写初始值 f[0] = 1 了, 放到下面循环中的 ++ 了
        for (int i = 0; i < n; ++i) {  // 依次计算每个 f[i] 的值
            f[i] = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            ++f[i];  // +1 代表 i
        }
        return ranges::max(f);
    }
};
// @leet end

int main() { return 0; }
