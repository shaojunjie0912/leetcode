#include <iostream>
#include <stack>

using namespace std;

// 弹出并返回<栈底>元素, 上面的元素盖下来
int BottomOut(stack<int>& nums) {
    int ans{nums.top()};
    nums.pop();
    if (nums.empty()) {
        return ans;
    }
    int last{BottomOut(nums)};
    nums.push(ans);
    return last;
}

// 使用递归逆序一个栈
void Reverse(stack<int>& nums) {
    if (nums.empty()) {
        return;
    }
    int num{BottomOut(nums)};
    Reverse(nums);
    nums.push(num);
}
