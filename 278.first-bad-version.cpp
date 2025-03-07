#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

bool isBadVersion(int version);

// NOTE: 二分查找? [g, g, g,..., g, b, b,...,b]
//                                ↑
// 本题不需要用数组下标 0 ~ n-1
// 1 ~ n 即可

// 记住吧...就是正常二分
// NOTE: 退出循环时, l 指向首个错误版本, r 指向最后一个正确版本

// @leet start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l{1}, r{n};  // HACK: 应用题: 第 1/n 个, 不用0,n-1
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {  // [g,...,b,.mid=b,.....b]
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;  // 越界退出循环后 l 一定指向第一个错误版本
    }
};
// @leet end

int main() {
    return 0;
}
