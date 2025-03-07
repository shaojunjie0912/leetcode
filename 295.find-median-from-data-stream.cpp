#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// HACK: 补充 C++ 知识
// 堆顶元素是“最优”元素（最大或最小）
// Compare(a, b) == true，说明优先级 a < b

// priority_queue<int, vector<int>, less<int>> 大顶堆
// priority_queue<int, vector<int>, greater<int>> 小顶堆

// NOTE: 使用两个堆
// 思考: 中位数将元素分成 "大的" 和 "小的"
// 目的:
// - "大的" <最终>进入小顶堆
// - "小的" <最终>进入大顶堆

// 对于总个数 n:
// n: 偶数: 保持小, 大顶堆个数: n/2
// n: 奇数: 保持小顶堆个数: (n+1)/2, 大顶堆个数: (n-1)/2 (小顶比大顶多一个)

// 奇数时, 小顶堆多出来的那个元素就是中位数
// 偶数时, 两个堆堆顶元素求平均

// e.g. 如果当前总个数为奇数, 则下一个元素<最终>进大顶堆(变成偶数平衡)
// e.g. 如果当前总个数为偶数, 则下一个元素<最终>进小顶堆(变成奇数平衡)
// 进大顶堆前, 以防是 "大元素" 误入, 要先进小顶堆"刷一遍", 再从小顶堆top取
// 进小顶堆前, 以防是 "小元素" 误入, 要先进大顶堆"刷一遍", 再从大顶堆top取

//     _____        _____
//    |_____        _____|
// 小顶堆(大元素)   大顶堆(小元素)

// @leet start
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap_;  // 小顶堆存放大元素
    priority_queue<int, vector<int>, less<int>> max_heap_;     // 大顶堆存放小元素
    // NOTE: 忘记初始化了!!!NONONONO!
    // int size_{0}; // NOTE: 通过两个堆大小是否相等也能判别奇偶

public:
    MedianFinder() {}

    void addNum(int num) {
        // 分奇偶
        if (min_heap_.size() != max_heap_.size()) {  // 当前奇数 -> 偶数平衡
            min_heap_.push(num);
            max_heap_.push(min_heap_.top());
            min_heap_.pop();
        } else {  // 当前偶数 -> 奇数平衡
            max_heap_.push(num);
            min_heap_.push(max_heap_.top());
            max_heap_.pop();
        }
    }

    double findMedian() {
        // 分奇偶
        if (min_heap_.size() != max_heap_.size()) {  // 奇数个
            return min_heap_.top();
        } else {                                               // 偶数个
            return (min_heap_.top() + max_heap_.top()) / 2.0;  // HACK: .0
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @leet end

int main() {
    return 0;
}
