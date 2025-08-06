#include <climits>
#include <stack>
#include <utility>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class MinStack {
private:
    stack<pair<int, int>> st;  // NOTE: 底层栈存放 pair<值, 最小值>

public:
    MinStack() {
        st.emplace(0, INT_MAX);  // 哨兵 (空栈特判, 前缀最小值)
    }

    void push(int val) { st.emplace(val, min(getMin(), val)); }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @leet end

int main() { return 0; }
