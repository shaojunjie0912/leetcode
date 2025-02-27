// https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
// NOTE: 溢出警告: long 是 32 位(Win)/ 64 位(Linux), 应该用 int64_t

#include <cstdint>
#include <iostream>

using namespace std;

static int help[100001] = {0};
static int arr[100001] = {0};

int64_t Merge(int l, int m, int r) {
    // =============== 统计 ================
    // NOTE: 左侧是累计区间
    int64_t ans = 0;
    // i 是左侧指针
    int i = l;  // i=l 不能放在 while j 循环中每次重置, 否则O(n^2)
    // j 是右侧指针
    int j = m + 1;
    // sum 是 i 左侧累加和
    int64_t sum = 0;  // sum 不能放在 while j 循环中重置, 需要根据有序辅助累加
    while (j <= r) {
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
        ++j;
    }

    // ================ 排序 ==================
    int a = l;
    int b = m + 1;
    int k = l;
    while (a <= m && b <= r) {
        help[k++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= m) {
        help[k++] = arr[a++];
    }
    while (b <= r) {
        help[k++] = arr[b++];
    }
    // help 覆写 arr
    for (int i = l; i <= r; ++i) {
        arr[i] = help[i];
    }
    return ans;
}

int64_t MergeSmallSum(int l, int r) {
    // 递归终止条件(当只有一个数时)
    if (l == r) {
        return 0;
    }
    int m = l + (r - l) / 2;
    return MergeSmallSum(l, m) + MergeSmallSum(m + 1, r) + Merge(l, m, r);
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    std::cout << MergeSmallSum(0, N - 1) << '\n';
    return 0;
}
