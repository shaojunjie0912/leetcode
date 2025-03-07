#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

bool isBadVersion(int version);

// NOTE: 二分查找? [g, g, g,..., g, b, b,...,b]
//                                ↑

// @leet start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l{0}, r{n - 1};
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {  // [g,...,b,.mid=b,.....b]
                r = mid;
            } else {
                l = mid;
            }
        }
    }
};
// @leet end

int main() {
    return 0;
}
