#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Bitset {
    // NOTE: 这道题额外使用了几个辅助变量
    // flip 很妙脆角! 借助 reverse_ 进行含义切换, 而不用重新按位改值
    // 默认未翻转
    // NOTE: 这道题字符串虽然是 0...31 的顺序
    // 但是只要处理 toString() 函数即可, 别的使用简单 31...0 顺序方便
public:
    Bitset(int size)
        : set_(vector<int>((size + 32 - 1) / 32)),
          size_(size),
          reverse_(false),
          zeros_(size),
          ones_(0) {}

    // NOTE: 始终抓住 zero: 无效, ones: 有效
    // 设有效
    void fix(int idx) {
        int index{idx / 32};
        int bit{idx % 32};
        // 未翻转
        if (!reverse_) {
            // 如果该位是 0 才置 1
            // 0: 不存在
            // 1: 存在
            if ((set_[index] & (1 << bit)) == 0) {
                --zeros_;
                ++ones_;
                set_[index] |= (1 << bit);
            }
        }
        // 翻转
        else {
            // 如果该位是 1 才置 0
            // 0: 存在
            // 1: 不存在
            if ((set_[index] & (1 << bit)) != 0) {  // NOTE: 判断位=1bit 而不是int!!!, 只能用 !=0
                --zeros_;  // HACK: 翻转了!! zeros_ 代表无效, 而翻转后置 0 为有效, ++ones_
                ++ones_;
                set_[index] ^= (1 << bit);  // NOTE: 置 0 方法: 异或或者与反都可
            }
        }
    }

    // 设无效
    void unfix(int idx) {
        int index{idx / 32};
        int bit{idx % 32};
        // 未翻转
        if (!reverse_) {
            // 如果该位是 1 才置 0
            if ((set_[index] & (1 << bit)) != 0) {
                ++zeros_;
                --ones_;
                set_[index] ^= (1 << bit);
            }
        }
        // 翻转
        else {
            // 如果该位是 0 才置 1
            if ((set_[index] & (1 << bit)) == 0) {
                ++zeros_;
                --ones_;
                set_[index] |= (1 << bit);
            }
        }
    }

    void flip() {
        reverse_ = !reverse_;  // HACK: 取相反状态, 这不是位运算!!
        std::swap(ones_, zeros_);
    }

    // 所有都为有效
    bool all() {
        // HACK: 判断 ones_ 的数量简单多了
        return ones_ == size_;
    }

    // 至少有一个有效
    bool one() {
        return ones_ > 0;  // 至少有一个即 > 0
    }

    // 有效的数目
    int count() {
        return ones_;
    }

    string toString() {
        string res;
        // k 是第 k 个 int
        // i 限制 < size
        for (int i = 0, k = 0, number, status; i < size_; ++k) {
            number = set_[k];
            for (int j{0}; j < 32 && i < size_; ++j, ++i) {
                status = (number >> j) & 1;
                status ^= (reverse_ ? 1 : 0);  // NOTE: 精髓: reverse_ 翻转表示
                res += to_string(status);
            }
        }
        return res;
    }

private:
    vector<int> set_;
    int size_;      // 可存储的数量
    int zeros_;     // NOTE: 无效 的数量(未翻: 0, 翻: 1)
    int ones_;      // NOTE: 有效 的数量(未翻: 1, 翻: 0)
    bool reverse_;  // 是否经历过翻转
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
// @leet end

int main() {
    return 0;
}
