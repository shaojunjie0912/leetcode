// 0-1 背包
// 所选物品体积和不超过 capacity 的前提下, 所能得到的最大价值和

#include <functional>
#include <vector>

using namespace std;

/**
 * @brief 0-1 背包问题 (递归 + 记忆化搜索)
 *
 * @param capacity 背包容量
 * @param w 物品体积数组
 * @param v 物品价值数组
 * @return int
 */
int ZeroOneKnapSack(int capacity, vector<int> const& w, vector<int> const& v) {
    int n = w.size();
    vector memo(n, vector<int>(capacity + 1, -1));  // 记忆数组 (i, c) 二维

    // dfs(i, c): 考虑前 i 个物品(0~i)，在容量为 c 的情况下，能获得的最大价值
    function<int(int, int)> dfs = [&](int i, int c) -> int {
        if (i < 0) {
            return 0;
        }
        auto& res = memo[i][c];  // NOTE: 读取 dfs(i, c) 的记忆 (引用)
        if (res != -1) {
            return res;
        }
        if (w[i] > c) {  // i 体积大于剩余体积, 只能不选
            res = dfs(i - 1, c);
        } else {  // 不选 / 选
            res = max(dfs(i - 1, c), dfs(i - 1, c - w[i]) + v[i]);
        }
        return res;
    };
    return dfs(n - 1, capacity);  // NOTE: n - 1
}

int Test(int capacity, vector<int> const& w, vector<int> const& v) {
    int n = w.size();
    vector memo(n, vector<int>(capacity + 1, -1));
    function<int(int, int)> dfs = [&](int i, int c) -> int {
        if (i < 0) {
            return 0;
        }
        auto& res{memo[i][c]};
        if (res != -1) {
            return res;
        }
        if (w[i] > c) {  // 只能不选
            return res = dfs(i - 1, c);
        } else {
            // max(不选, 选)
            return res = max(dfs(i - 1, c), dfs(i - 1, c - w[i]) + v[i]);
        }
    };
    return dfs(n - 1, capacity);
}

int main() {}