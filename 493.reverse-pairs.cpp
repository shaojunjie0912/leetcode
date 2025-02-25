#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
static int help[50001] = {0};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return MergeReversePairs(nums, 0, nums.size() - 1);
    }

    int MergeReversePairs(vector<int>& arr, int l, int r) {
        // 终止条件
        if (l == r) {
            return 0;
        }
        int m = l + (r - l) / 2;
        return MergeReversePairs(arr, l, m) + MergeReversePairs(arr, m + 1, r) + Merge(arr, l, m, r);
    }

    int Merge(vector<int>& arr, int l, int m, int r) {
        int ans = 0;
        // =============== 统计 ================
        // NOTE: 右侧是累计区间
        int i = l;
        int j = m + 1;
        int sum = 0;
        while (i <= m) {
            // NOTE: 溢出 临时变量强制转换即可
            while (j <= r && (int64_t)arr[i] > (int64_t)2 * arr[j]) {
                ++sum;
                ++j;  // NOTE: 记得更新右侧j
            }
            ans += sum;
            ++i;
        }
        // ================ 排序 ==================
        int a = l;
        int b = m + 1;
        int k = l;
        while (a <= m && b <= r) {
            help[k++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
        }
        while (a <= m) {
            help[k++] = arr[a++];
        }
        while (b <= r) {
            help[k++] = arr[b++];
        }
        //  覆写 arr
        for (int i = l; i <= r; ++i) {
            arr[i] = help[i];
        }

        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
