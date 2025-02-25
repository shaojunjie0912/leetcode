#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class MyQueue {
    // 使用两个栈(in+out)实现队列
    // in 栈: 对应 push 操作
    // out 栈: 对应 pop 操作
    // NOTE: 1. out 为空才能移动 in->out
    // NOTE: 2. 当移动 in->out 时必须移动 in 中所有
public:
    MyQueue() {}

    void push(int x) {
        stack_in_.push(x);
    }

    int pop() {
        int top = peek();
        stack_out_.pop();
        return top;
    }

    int peek() {
        if (stack_out_.empty()) {
            while (!stack_in_.empty()) {
                stack_out_.push(stack_in_.top());
                stack_in_.pop();
            }
        }

        return stack_out_.top();
    }

    bool empty() {
        return stack_in_.empty() && stack_out_.empty();
    }

private:
    std::stack<int> stack_in_;
    std::stack<int> stack_out_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @leet end

int main() {
    return 0;
}
