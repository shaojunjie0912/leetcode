#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class MyCircularQueue {
public:
    // NOTE: 循环队列使用 size 记录队列大小，此时 l-r 已经无效
    MyCircularQueue(int k) : ac_queue_(new int[k]), l_(0), r_(0), size_(0), limit_(k) {}

    ~MyCircularQueue() {
        if (ac_queue_) {
            delete[] ac_queue_;
        }
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        ac_queue_[r_] = value;
        r_ = (r_ == limit_ - 1) ? 0 : (r_ + 1);
        ++size_;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        l_ = (l_ == limit_ - 1) ? 0 : (l_ + 1);
        --size_;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return ac_queue_[l_];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        // NOTE: 如果 r_ 是 0, 说明是从 limit 跳转来的
        // 不然 0-1=-1 访问越界
        if (r_ == 0) {
            return ac_queue_[limit_ - 1];
        } else {
            return ac_queue_[r_ - 1];
        }
    }

    bool isEmpty() {
        return size_ == 0;
    }

    bool isFull() {
        return size_ == limit_;
    }

private:
    int* ac_queue_;  // 底层数组
    int l_;          // 区间左 [
    int r_;          // 区间右 )
    int size_;       // 当前队列大小
    int limit_;      // 队列最多可容纳的元素数量
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @leet end

int main() {
    return 0;
}
