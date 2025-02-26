// >= n 最小的 2 的幂

int near2power(int n, int &power) {
    if (n <= 0) {
        return 1;
    }
    // NOTE: 先减一(⭐️)
    --n;
    // NOTE: 将右侧的位全部刷成 1
    n |= n >> 1;  // HACK: java 中是 >>> 相当于 c++ 无符号[数]右移
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;  // NOTE: 最后还要加上 1 变成 2 的幂
}
