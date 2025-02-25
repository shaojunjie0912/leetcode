#include <cstdio>
#include <stack>

#include "include/tree_node.hpp"

void PreOrderNoRecursion(TreeNode* head) {
    if (!head) {
        return;
    }
    std::stack<TreeNode*> stack;
    stack.push(head);
    while (!stack.empty()) {
        auto top = stack.top();
        stack.pop();  // 弹出栈顶结点并打印
        std::printf("%d, ", top->val);
        if (top->right) {
            stack.push(top->right);  // 先压入右结点
        }
        if (top->left) {
            stack.push(top->left);  // 再压入左结点
        }
    }
    std::printf("\n");
    return;
}

void InOrderNoRecursion(TreeNode* head) {
    if (!head) {
        return;
    }
}

int main() {
    TreeNode* head = new TreeNode{1};
    head->left = new TreeNode{2};
    head->right = new TreeNode{3};
    head->left->left = new TreeNode{4};
    head->left->right = new TreeNode{5};
    head->right->left = new TreeNode{6};
    head->right->right = new TreeNode{7};
    PreOrderNoRecursion(head);
    return 0;
}
