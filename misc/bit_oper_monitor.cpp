// 位运算模拟四则算术运算
// NOTE: 只能按照补码的方式去理解

#include <iostream>
#include <type_traits>

template <typename T>
concept Intergral = std::is_integral_v<T>;

// 无符号右移
template <Intergral T>
T UnsignedRightShift(T value, int shift) {
    return static_cast<T>((static_cast<std::make_unsigned_t<T>>(value)) >> shift);
}

// TODO: dsa

// 加法
// NOTE: 无进位相加 ^ 进位结果(直至进位消失)
// NOTE: 对负数也同样成立
int Add(int a, int b) {
    // NOTE: 巧妙: ans 存 a, 如果 b==0 直接返回 a
    int ans = a;
    while (b != 0) {         // 如果进位消失则退出
        ans = a ^ b;         // 异或: 无进位相加
        b = ((a & b) << 1);  // HACK: 按位与+左移得到真正进位结果
        a = ans;
    }
    return ans;
}

// 计算一个数的相反数: 按位取反 + 1
int Neg(int n) {
    return Add(~n, 1);
}

// 减法
int Minus(int a, int b) {
    // a - b = a + (-b)
    return Add(a, Neg(b));
}

// 乘法
// NOTE: 遵循一般乘法规则(必须以**补码**理解)
// a 10010101 是乘数
//      *
// b 10101010 中的 bit 是因子
int Multiply(int a, int b) {
    int ans = 0;
    while (b != 0) {
        // NOTE: 如果 b 最右侧 bit 为 1, 则加上 a
        // 如果是 0 则不加 a, 直接右移到下一位(跟乘法一样, 跳到下一行)
        // 每次 a 都左移 1 位, 右边补 0
        if ((b & 1) != 0) {
            ans = Add(ans, a);
        }
        a <<= 1;  // a 左移
        // b >>= 1;  // HACK: b 无符号右移
        b = UnsignedRightShift(b, 1);
    }
    return ans;
}

// 除法

int main() {
    // std::cout << Add(-2, -3) << '\n';
    std::cout << Multiply(-2, -2) << '\n';
    return 0;
}
