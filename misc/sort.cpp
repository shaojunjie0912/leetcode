#include <iostream>
#include <utility>
#include <vector>

using namespace std;

namespace quick_sort {

// 哨兵划分
int Partition(vector<int>& nums, int l, int r) {
    int i{l}, j{r};

    // nums[l] 作为基准数
    while (i < j) {
        // 从右往左找第一个小于基准数的元素
        while (i < j && nums[j] >= nums[l]) {
            --j;
        }
        // 从左往右找第一个大于基准数的元素
        while (i < j && nums[i] <= nums[l]) {
            ++i;
        }
        std::swap(nums[i], nums[j]);  // 交换这两个元素
    }
    std::swap(nums[l], nums[i]);  // 交换基准数至两个子数组分界线

    return i;
}

void Sort(vector<int>& nums, int l, int r) {
    // [ ) 边界条件
    if (l >= r) {
        return;
    }
    int pivot = Partition(nums, l, r);
    Sort(nums, l, pivot - 1);
    Sort(nums, pivot + 1, r);
}

}  // namespace quick_sort

int main() {
    vector<int> nums{3, 2, 5, 6, 4, 9, 8, 10, 7};
    int n = nums.size();
    quick_sort::Sort(nums, 0, n - 1);
    for (auto& x : nums) {
        cout << x << ' ';
    }
    cout << '\n';
}