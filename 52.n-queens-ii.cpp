#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// 记住:
// if 绝对值 |当前行 - 之前行| == |当前列 - 之前列|
// then: 两个皇后在对角线上(注意: 有两条对角线)

// @leet start
class Solution {
public:
    int totalNQueens(int n) {
#if 1
        // 解法二: 位运算(好!)
        // limit = (1<<n) - 1
        return R2((1 << n) - 1, 0, 0, 0);
#else
        // 解法一: 数组(速度慢)
        vector<int> path(n);
        return R1(path, 0, n);
#endif
    }
    // ==================================================
    // ==================== 位运算 ========================
    // ==================================================
    // limit: 根据问题规模对皇后数量进行限制(eg. 4 皇后: 0...01111)
    // col: 之前皇后的列限制(即col某一位为1则下一行某一列就不能摆放)
    // left: 之前皇后的 ↙ 对角线限制
    // right: 之前皇后的 ↘ 对角线限制
    int R2(int limit, int col, int left, int right) {
        if (col == limit) {  // 终止条件: 已到达完全限制
            return 1;
        }
        // 总限制 = 列限制 | ↙对角线限制 | ↘对角线限制
        // 0 可放, 1 不可放
        int ban = col | left | right;
        // 可以摆放的候选位置(取反: 1 可放, 0 不可放 )
        // NOTE: 用 limit 限制规模
        int candidate = limit & (~ban);
        // HACK: 放置皇后的尝试!!(理解为循环中列的选择)
        int place = 0;
        int ans = 0;
        while (candidate) {  // 0 说明没有可选位置(NOTE: 又多加!)
            // old candidate: 0 0 1 1 1 0
            //   ^
            // place:         0 0 0 0 1 0
            //  ＝
            // new candidate: 0 0 1 1 0 0
            place = candidate & (-candidate);  // 提取最右边的 1 (K 算法)
            candidate ^= place;                // 将皇后摆放在最右边的 1(无进位相加)
            // 执行剩下的递归
            // 列限制: 直接 col | place(当前行摆放皇后位置)
            // ↙ 对角线限制: (left | place) >> 1 (NOTE: 31...2 1 0)
            // ↘ 对角线限制: (right | place) << 1
            ans += R2(limit, col | place, (left | place) >> 1, (right | place) << 1);
        }
        return ans;
    }

    // ==================================================
    // ==================== 数组 ========================
    // ==================================================

    // path[]: 之前的0~i-1个皇后的位置, path[k]: 第 k 行, 第 path[k] 列
    // i: 当前行(每到当前行, 都会按列去尝试)
    // n: 问题规模: n * n 棋盘
    // return: 0~i-1行已经摆完, i~n-1行尝试后有效的方法
    int R1(vector<int>& path, int i, int n) {
        if (i == n) {  // 终止条件: 最后一行结束
            return 1;  // 因为全部摆完了, 增加一种方法
        }
        int ans = 0;
        // NOTE: 思考: 如果j跑完一轮都不满足
        // 那么该层递归就返回了, 且 ans = 0, 即在当前最外层
        // i = 0, j = k 情况下, 没有符合的, 接着 ++j 尝试别的 j
        for (int j = 0; j < n; ++j) {
            // 如果当前位置满足才继续递归
            if (Check(path, i, j)) {
                path[i] = j;  // 把第 i 行皇后摆在第 j 列
                // 当做出上面决定后, 执行逻辑得到后续还有多少方法
                // 累加起来就是该层递归最终的方法数
                ans += R1(path, i + 1, n);  // TODO: 为什么是 i+1
            }
        }
        return ans;
    }

    // HACK: 检查当前摆放的皇后是否有效
    // 当前在
    // i: i 行
    // j: j 列
    // 摆了一个皇后
    // path[]: 之前的0~i-1个皇后的位置, path[k]: 第 k 行, 第 path[k] 列
    bool Check(vector<int>& path, int i, int j) {
        for (int k = 0; k < i; ++k) {
            // 其实已经不在同一行了, 所以这里要确保
            // 1. 不在同一列
            // 2. 不在每个位置两条对角线上(用差绝对值公式判断)
            if ((path[k] == j) || (abs(i - k) == abs(j - path[k]))) {
                return false;
            }
        }
        return true;
    }
};
// @leet end

int main() {
    return 0;
}
