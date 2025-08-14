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
    priority_queue<int, vector<int>, less<int>> max_heap;
    // 小顶堆: 存放较大的一部分
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    MedianFinder() {}

    void addNum(int num) {
        // 1. 无条件把num先压入大顶堆
        max_heap.push(num);
        // 2. 维护数值平衡: 大顶堆元素 <= 小顶堆元素, 转移元素到小顶堆
        min_heap.push(max_heap.top());
        max_heap.pop();
        // 3. 维护数量平衡: 转移元素到大顶堆
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        return max_heap.size() == min_heap.size() ? (max_heap.top() + min_heap.top()) / 2.0
                                                  : max_heap.top();
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
