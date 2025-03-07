#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start

class MinStack {
private:
    std::stack<int> data_stack_;  // 基本栈(保存所有元素)
    // NOTE: 元素值小则同进同出
    std::stack<int> min_stack_;  // 最小栈(只保存最小)

public:
    // 只记得好像要一个辅助栈?
    // min_stack_ 只要保存最小元素即可, 而不是所有
    MinStack() {}

    void push(int val) {
        // NOTE: 这里val==min_stack_.top()也要压入最小栈
        // 因为弹出的时候用了==区分
        if (min_stack_.empty() || val <= min_stack_.top()) {
            min_stack_.push(val);
        }
        data_stack_.push(val);
    }

    void pop() {
        // NOTE:
        if (data_stack_.top() == min_stack_.top()) {
            min_stack_.pop();
        }
        data_stack_.pop();
    }

    int top() {
        return data_stack_.top();
    }

    int getMin() {
        return min_stack_.top();
    }
};
// class MinStack {
// public:
//     MinStack() {}

//     // 使用两个栈: 数据栈+最小栈
//     // NOTE: 两个栈的size要同步更新
//     // min_stack 同步压入 val 和 栈顶元素中较小的那个
//     void push(int val) {
//         data_stack_.push(val);
//         // 最小栈非空 且 min_stack 栈顶元素较小
//         if (!min_stack_.empty() && val > min_stack_.top()) {
//             min_stack_.push(min_stack_.top());
//         }
//         // 最小栈为空 或 val 较小
//         else {
//             min_stack_.push(val);
//         }
//     }

//     void pop() {
//         data_stack_.pop();
//         min_stack_.pop();
//     }

//     int top() {
//         return data_stack_.top();
//     }

//     int getMin() {
//         return min_stack_.top();
//     }

// private:
//     std::stack<int> data_stack_;
//     std::stack<int> min_stack_;
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @leet end

int main() {
    return 0;
}
