#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 维护两个不变量
// 1. 数量平衡
//    - 大顶堆元素数量 = 小顶堆元素数量 (偶数)
//    - 大顶堆元素数量 = 小顶堆元素数量 + 1 (奇数)
// 2. 数值平衡
//    - 大顶堆堆顶 <= 小顶堆堆顶

// @leet start
class MedianFinder {
private:
    // 大顶堆: 存放较小的一部分
    priority_queue<int, vector<int>, less<int>> small_half;
    // 小顶堆: 存放较大的一部分
    priority_queue<int, vector<int>, greater<int>> large_half;

public:
    MedianFinder() {}

    // 时间复杂度: O(logn)
    void addNum(int num) {
        // NOTE: 1. 无条件把num先压入大顶堆
        small_half.push(num);
        // 2. 维护数值平衡: 将 small_half 的最大值（堆顶）移到 large_half
        // 这一步确保了 small_half 的所有元素 <= large_half 的所有元素
        large_half.push(small_half.top());
        small_half.pop();
        // 3. 维护数量平衡: 转移元素到大顶堆
        // 如果 large_half 的大小大于 small_half，将 large_half 的最小值移回 small_half
        if (small_half.size() < large_half.size()) {
            small_half.push(large_half.top());
            large_half.pop();
        }
    }

    // 时间复杂度: O(1)
    double findMedian() {
        return small_half.size() == large_half.size() ? (small_half.top() + large_half.top()) / 2.0
                                                      : small_half.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @leet end

int main() { return 0; }
