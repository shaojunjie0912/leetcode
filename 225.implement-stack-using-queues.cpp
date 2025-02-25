#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class MyStack {
public:
    MyStack() {}

    // NOTE: 从队列首弹出, 从队列尾压入, 该操作重复 size 次
    void push(int x) {
        int size = queue_.size();  // 先存储插入之前的大小
        queue_.push(x);            // 再插入元素
        while (size--) {           // 调整之前的 size 个元素顺序
            int head = queue_.front();
            queue_.pop();
            queue_.push(head);
        }
    }

    int pop() {
        int head = queue_.front();
        queue_.pop();
        return head;
    }

    int top() {
        return queue_.front();
    }

    bool empty() {
        return queue_.empty();
    }

private:
    std::queue<int> queue_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @leet end

int main() {
    return 0;
}
