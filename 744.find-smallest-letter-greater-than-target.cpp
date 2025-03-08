#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // 第一个 > target: 第一个 >= target + 1
        auto it{ranges::lower_bound(letters, target + 1)};
        if (it != end(letters)) {  // 存在
            return *it;
        } else {  // 不存在
            return letters[0];
        }
    }
};
// @leet end

int main() {
    return 0;
}
