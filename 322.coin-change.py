from typing import List, Dict, Tuple, Literal
from functools import cache
from math import inf

# 完全背包, 选或不选
# dfs(i, c) = min(dfs(i - 1, c), dfs(i, c - w[i]) + v[i])

# 总金额: capacity
# 单种硬币面额: w[i]
# 单种硬币个数: v[i], 本题都是 1
# dfs(i, c) = min(dfs(i - 1, c), dfs(i, c - w[i]) + 1)


# @leet start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        method: Literal["DFS_MEMO", "DP_2D_F", "DP_1D_F"] = "DP_1D_F"
        match method:
            case "DFS_MEMO":
                return self.SolveDfsMemo(coins, amount)
            case "DP_2D_F":
                return self.SolveDp2dF(coins, amount)
            case "DP_1D_F":
                return self.SolveDp1dF(coins, amount)
            case _:
                raise NotImplementedError

    # dfs(i, c) = min(dfs(i - 1, c), dfs(i, c - w[i]) + 1)
    def SolveDfsMemo(self, coins: List[int], amount: int) -> int:
        n = len(coins)

        @cache
        def dfs(i: int, c: int) -> int:
            if i < 0:  # 边界条件
                return 0 if c == 0 else inf
            if coins[i] > c:  # 只能不选
                return dfs(i - 1, c)
            # 选/不选
            return min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1)

        ans = dfs(n - 1, amount)
        return ans if ans < inf else -1

    # NOTE: Again: f 数组偏移防止访问越界 0 ~ n
    # f[i + 1][c] = min(f[i][c], f[i + 1][c - w[i]] + 1)
    def SolveDp2dF(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        # NOTE: Again: f 数组偏移防止访问越界, 所以是 n + 1
        f = [[inf] * (amount + 1) for _ in range(n + 1)]
        f[0][0] = 0  # 初始值

        # 递归改循环
        for i, x in enumerate(coins):  # NOTE: 这里只到 n-1, 然后 i+1 得到 n 了
            for c in range(amount + 1):
                if x > c:  # 不能选
                    f[i + 1][c] = f[i][c]
                else:  # 不选/选
                    f[i + 1][c] = min(f[i][c], f[i + 1][c - x] + 1)

        ans = f[n][amount]
        return ans if ans < inf else -1

    # f[c] = min(f[c], f[c - w[i]] + 1)
    def SolveDp1dF(self, coins: List[int], amount: int) -> int:
        f = [0] + [inf] * amount  # NOTE: 这里长度是 amount + 1 不是 n + 1
        # 同样的双重循环, 但是正序计算, 且只取 c >= x 部分
        for x in coins:
            for c in range(x, amount + 1):
                f[c] = min(f[c], f[c - x] + 1)
        ans = f[amount]  # NOTE: 这里是 f[amount] 不是 f[n]
        return ans if ans < inf else -1


# @leet end

if __name__ == "__main__":
    pass
