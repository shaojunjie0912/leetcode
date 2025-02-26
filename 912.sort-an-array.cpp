#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
// 归并排序
namespace merge_sort {

static int help[50001] = {0};

void Merge(vector<int>& arr, int l, int m, int r) {
    int a = l;      // 左侧区间比较指针
    int b = m + 1;  // 右侧区间比较指针
    int k = l;      // 辅助数组指针

    // 逐个比较左右区间元素大小, 将小的插入help
    while (a <= m && b <= r) {
        help[k++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    // 插入剩余元素
    while (a <= m) {
        help[k++] = arr[a++];
    }
    // 插入剩余元素
    while (b <= r) {
        help[k++] = arr[b++];
    }

    // 覆写arr<对应位置>
    for (k = l; k <= r; ++k) {
        arr[k] = help[k];
    }
}

// 递归
void Sort(vector<int>& arr, int l, int r) {
    if (l == r) {
        return;
    }
    int m = l + (r - l) / 2;
    Sort(arr, l, m);      // 排序左侧区间
    Sort(arr, m + 1, r);  // 排序右侧区间
    Merge(arr, l, m, r);  // 合并
}

// 非递归
void SortNoRec(vector<int>& arr) {
    int n = arr.size();
    // 根据步长左右分组
    for (int step = 1; step < n; step *= 2) {
        int l = 0;  // 左区间首
        while (l < n) {
            int m = l + step - 1;
            if (m + 1 >= n) {
                break;
            }
            int r = std::min(l + step * 2 - 1, n - 1);
            Merge(arr, l, m, r);
            l = r + 1;
        }
    }
}

}  // namespace merge_sort

// 随机快速排序
namespace quick_sort {

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

// NOTE: 需要返回 x 的索引
// 分区(未优化)
int PartitionNoOp(vector<int>& arr, int l, int r, int x) {
    int a = l;  // arr[l, ..., a-1] 是 <= x 的区域
    int xi = -1;
    // 划分元素
    for (int i = l; i <= r; i++) {
        // 如果当前元素小于分界元素 x
        if (arr[i] <= x) {
            std::swap(arr[a], arr[i]);  // 交换索引a和i处元素
            if (arr[a] == x) {          // a 处已经是原来 i 的元素
                xi = a;
            }
            ++a;  // 移动 a 和 i
        }
        // 否则只移动 i
    }
    // 将分界元素移动至分界线
    std::swap(arr[xi], arr[a - 1]);
    // 返回分界线 a-1
    return a - 1;
}

// 随机快排(未优化)
void SortNoOp(vector<int>& arr, int l, int r) {
    // 终止条件: l == r 或 l > r
    if (l >= r) {
        return;
    }
    int x = arr[RandomInt(l, r)];  // 随机选取一个元素 x
    int mid = PartitionNoOp(arr, l, r, x);
    SortNoOp(arr, l, mid - 1);
    SortNoOp(arr, mid + 1, r);
}

// 分区(荷兰国旗优化版, 需要返回左右边界)
// < x] a..==x..b [> x
// < x 放左边
// = x 放中间
// > x 放右边
std::pair<int, int> Partition(vector<int>& arr, int l, int r, int x) {
    int i = l;
    int a = l;  // 左边界
    int b = r;  // 右边界
    // while 相比于 for 更好地控制 i
    while (i <= b) {
        // 如果当前元素 < x
        if (arr[i] < x) {
            std::swap(arr[a], arr[i]);
            ++a;
            ++i;  // 同时移动 a 和 i
        }
        // 如果当前元素 > x
        else if (arr[i] > x) {
            std::swap(arr[b], arr[i]);
            --b;  // 只移动 b
        }
        // 如果当前元素 = x
        else {
            ++i;  // 只移动 i
        }
    }
    return {a, b};  // 返回左右边界
}

// 随机快排(优化版)
void Sort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int x = arr[RandomInt(l, r)];          // 随机取一个元素 x
    auto bound = Partition(arr, l, r, x);  // 获取左右边界
    // 中间相等区不用排序
    Sort(arr, l, bound.first - 1);   // 排序左侧 < x 区域
    Sort(arr, bound.second + 1, r);  // 排序右侧 > x 区域
}

}  // namespace quick_sort

// 堆排序
namespace heap_sort {

void Sort(char const* p) {
    p = "dsadsa";
}

}  // namespace heap_sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() > 1) {
            // merge_sort::Sort(nums, 0, nums.size() - 1);
            srand((unsigned)time(NULL));
            // quick_sort::SortNoOp(nums, 0, nums.size() - 1);
            quick_sort::Sort(nums, 0, nums.size() - 1);
        }
        return nums;
    }
};
// @leet end

int main() {
    return 0;
}
