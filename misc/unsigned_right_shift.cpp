#include <bitset>
#include <concepts>
#include <cstdint>
#include <iostream>
#include <type_traits>

template <typename T>
concept Intergral = std::is_integral_v<T>;

template <Intergral T>
T UnsignedRightShift(T value, int shift) {
    return static_cast<T>((static_cast<std::make_unsigned_t<T>>(value)) >> shift);
}

int main() {
    int16_t a = -1;
    std::cout << std::bitset<16>(a) << '\n';
    std::cout << std::bitset<16>(UnsignedRightShift(a, 2)) << '\n';
}
