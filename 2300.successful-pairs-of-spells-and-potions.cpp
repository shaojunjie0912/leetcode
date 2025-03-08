#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// @leet start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // vector<int> pairs; // NOTE: 后面直接修改 spells, 省空间
        ranges::sort(potions);  // 对 potions 进行从小到大排序

        // 遍历 spells, 在 potions 中找到 >= success/spells[i] 的第一个数
        for (auto& sp : spells) {
            // NOTE: success 是 int64_t, target 也要!
            // NOTE: a/b向上取整: (a+b-1)/b
            int64_t target = (success + sp - 1) / sp;

            // HACK: 由于 potions[int] 最大值确定, 因此提前判断
            // 思考: potions 中元素都是 int, 不加判断则都被转为 int64_t 浪费
            // 加了判断只要将 target 转 int, 因为 potions 一定都在 int 范围内
            if (target <= potions.back()) {
                // NOTE: 用 end 减 iter, 一开始写反了
                // 原地修改
                sp = std::end(potions) - ranges::lower_bound(potions, (int)target);
            } else {
                sp = 0;
            }
        }
        return spells;
    }
};
// @leet end

int main() {
    return 0;
}
