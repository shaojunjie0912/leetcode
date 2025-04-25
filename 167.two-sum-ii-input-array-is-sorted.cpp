#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 双指针

// @leet start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] > target) {
                --right;
            } else if (numbers[left] + numbers[right] < target) {
                ++left;
            } else {
                break;
            }
        }
        return {left + 1, right + 1};  // ? 下标从 1 开始
    }
};
// @leet end

int main() { return 0; }
