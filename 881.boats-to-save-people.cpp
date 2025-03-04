#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    // NOTE: 先排序 + 双指针
    int numRescueBoats(vector<int>& people, int limit) {
        if (people.size() == 1) {
            return 1;
        }
        std::sort(people.begin(), people.end());  // 排序(左小, 右大)
        int l = 0;
        int r = people.size() - 1;
        int ans = 0;
        while (l <= r) {
            // HACK: 如果是奇数个, 那么l 和 r 可能同时来到一个人
            // 此时不能加两个人!!!
            int sum = (l == r) ? people[l] : people[l] + people[r];
            if (sum > limit) {  // 大的单独一张船
                --r;
                ++ans;
            } else {  // 两人一张船
                ++l;
                --r;
                ++ans;
            }
        }
        return ans;
    }
};
// @leet end

int main() {
    return 0;
}
