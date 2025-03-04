#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 双指针
    // 从最后一个位置往奇/偶位置<发货>
    // 奇/偶任何一个越界就结束
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even{0};
        int odd{1};
        while (even < nums.size() && odd < nums.size()) {
            if ((nums.back() & 1) == 1) {  // 奇数&1=1, 偶数&1=0
                std::swap(nums.back(), nums[odd]);
                odd += 2;
            } else {
                std::swap(nums.back(), nums[even]);
                even += 2;
            }
        }
        return nums;
    }
};
// @leet end

int main() {
    return 0;
}
