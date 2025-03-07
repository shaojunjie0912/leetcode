#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class MyQueue {
private:
    std::stack<int> s1_;  // 入队列的元素
    std::stack<int> s2_;  // 出队列的元素

public:
    MyQueue() {}

    // NOTE: 入逻辑:
    // s1_ 是入队列的元素(没啥逻辑, 直接进, 主要是后面pop peek)
    void push(int x) {
        s1_.push(x);
    }

    // NOTE: 出逻辑:(这里借用peek省点代码)
    // 首先, s2_ 是出队列的元素
    // 如果 s2_ 空, 则转移所有 s1_ 中元素到 s2_
    // 否则直接弹出
    int pop() {
        auto top{peek()};
        s2_.pop();
        return top;
    }

    // NOTE: peek() 与 pop 相同逻辑
    int peek() {
        if (s2_.empty()) {
            while (!s1_.empty()) {
                s2_.push(s1_.top());
                s1_.pop();
            }
        }
        return s2_.top();
    }

    bool empty() {
        return s1_.empty() && s2_.empty();
    }
};

// class MyQueue {
//     // 使用两个栈(in+out)实现队列
//     // in 栈: 对应 push 操作
//     // out 栈: 对应 pop 操作
//     // NOTE: 1. out 为空才能移动 in->out
//     // NOTE: 2. 当移动 in->out 时必须移动 in 中所有
// public:
//     MyQueue() {}

//     void push(int x) {
//         stack_in_.push(x);
//     }

//     int pop() {
//         int top = peek();
//         stack_out_.pop();
//         return top;
//     }

//     int peek() {
//         if (stack_out_.empty()) {
//             while (!stack_in_.empty()) {
//                 stack_out_.push(stack_in_.top());
//                 stack_in_.pop();
//             }
//         }

//         return stack_out_.top();
//     }

//     bool empty() {
//         return stack_in_.empty() && stack_out_.empty();
//     }

// private:
//     std::stack<int> stack_in_;
//     std::stack<int> stack_out_;
// };

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
