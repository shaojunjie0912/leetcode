#include <format>
#include <iostream>
#include <random>
#include <set>
#include <vector>

using std::cout;

class BitSet {
public:
    // 位图支持: 0 ~ n-1
    // NOTE: n/32 向上取整
    // HACK: a, b >=0 则 a/b 向上取整: (a + b - 1) / b
    // 不能用 n/32+1 无法处理32的情况!!
    BitSet(int n) : set_(std::vector<int>((n + 32 - 1) / 32)) {}

    // NOTE: 31.......0
public:
    void Add(int num) {
        set_[num / 32] |= (1 << (num % 32));  // 或1就置一
    }

    void Remove(int num) {
        // NOTE: 别忘记取反~运算符
        set_[num / 32] &= ~(1 << (num % 32));  // 与取反后的1就是0
    }

    void Reverse(int num) {
        set_[num / 32] ^= (1 << (num % 32));  // 异或 1 将 0/1 翻转
    }

    bool Contains(int num) {
        // 1.
        // return ((set_[num / 32] >> (num % 32)) & 1) == 1;  // 右移 num%32 再与 1是否等于1
        // 2.
        return (set_[num / 32] & (1 << (num % 32))) != 0;  //
    }

private:
    std::vector<int> set_;
};

int RandomInt(int min, int max) {
    static std::mt19937 gen{std::random_device{}()};  // 静态随机数引擎
    static std::uniform_int_distribution<int> dist{min, max};
    return dist(gen);
}

double RandomDouble(double min, double max) {
    static std::mt19937 gen{std::random_device{}()};  // 静态随机数引擎
    static std::uniform_real_distribution<double> dist{min, max};
    return dist(gen);
}

// 对数器验证
int main() {
    int n{1000};
    int test_times{10000};
    auto bit_set{BitSet{n}};
    auto hash_set{std::set<int>{}};

    std::cout << "==== 开始调用 ====\n";
    for (int i{0}; i < test_times; ++i) {
        double decide{RandomDouble(0, 1)};
        int number{RandomInt(0, n - 1)};
        // NOTE: 每 1/3 概率测试成员函数 Add, Remove, Reverse:
        if (decide < 0.333) {
            bit_set.Add(number);
            hash_set.insert(number);
        } else if (decide < 0.666) {
            bit_set.Remove(number);
            hash_set.erase(number);
        } else {
            bit_set.Reverse(number);
            if (hash_set.contains(number)) {
                hash_set.erase(number);
            } else {
                hash_set.insert(number);
            }
        }
    }

    std::cout << "==== 开始验证 ====\n";
    for (int i{0}; i < n; ++i) {
        if (bit_set.Contains(i) != hash_set.contains(i)) {
            std::cout << "出错: " << i << '\n';
        }
    }
    std::cout << "==== 验证结束 ====\n";

    return 0;
}
