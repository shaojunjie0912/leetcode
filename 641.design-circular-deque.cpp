#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
#if 1
// 基于[固定数组]实现<循环>-<双端>队列
class MyCircularDeque {
    // [l, r] 闭区间
    // NOTE: [0, 0] 对应两种特殊情况: 0 个元素和 1 个元素
    // 用 size 控制边界
    // NOTE: size = 1 是特殊情况, 即假设只剩1个元素, 删除时只用 --size 即可, 不能移动l/r
public:
    MyCircularDeque(int k) : a_cdeque_(new int[k]), l_(0), r_(0), size_(0), limit_(k) {}

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            l_ = (l_ == 0) ? limit_ - 1 : l_ - 1;
        }
        a_cdeque_[l_] = value;
        ++size_;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            r_ = (r_ == limit_ - 1) ? 0 : r_ + 1;
        }
        a_cdeque_[r_] = value;
        ++size_;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        // NOTE: 如果当前 size = 1 时删除元素, 不需要移动 l / r
        if (size_ > 1) {
            l_ = (l_ == limit_ - 1) ? 0 : l_ + 1;
        }
        --size_;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        // NOTE: 如果当前 size = 1 时删除元素, 不需要移动 l / r
        if (size_ > 1) {
            r_ = (r_ == 0) ? limit_ - 1 : r_ - 1;
        }
        --size_;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return a_cdeque_[l_];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return a_cdeque_[r_];
    }

    bool isEmpty() {
        return size_ == 0;
    }

    bool isFull() {
        return size_ == limit_;
    }

    void PrintArray() const {
        for (int i = 0; i < limit_; ++i) {
            printf("%d ", a_cdeque_[i]);
        }
        printf("\n");
    }

private:
    int* a_cdeque_;  // 循环双端队列的底层数组
    int l_;
    int r_;
    int size_;
    int limit_;
};
#else
// 基于[双链表]实现<循环>-<双端>队列
// NOTE: 直接调用接口？
class MyCircularDeque {
public:
    MyCircularDeque(int k) {}

    bool insertFront(int value) {}

    bool insertLast(int value) {}

    bool deleteFront() {}

    bool deleteLast() {}

    int getFront() {}

    int getRear() {}

    bool isEmpty() {}

    bool isFull() {}

private:
    int size_;
    int limit_;
    std::list<int> list_;
};
#endif

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @leet end

int main() {
    MyCircularDeque ac_deque(2);
    ac_deque.insertFront(7);

    ac_deque.deleteLast();

    std::cout << ac_deque.getFront() << '\n';

    ac_deque.insertLast(5);

    ac_deque.insertFront(0);

    std::cout << ac_deque.getFront() << '\n';
    std::cout << ac_deque.getRear() << '\n';
    std::cout << ac_deque.getFront() << '\n';
    std::cout << ac_deque.getFront() << '\n';
    std::cout << ac_deque.getRear() << '\n';

    ac_deque.insertLast(0);
    ac_deque.PrintArray();

    return 0;
}
