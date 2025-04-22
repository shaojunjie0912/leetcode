from typing import List, Dict, Tuple, Literal
from functools import cache

# 不选/选
# dfs(i, c) = dfs(i-1, c) + dfs(i-1, c - w[i])


# @leet start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        method: Literal["DFS_MEMO", "DP_F"] = "DP_F"
        match method:
            case "DFS_MEMO":
                return self.SolveDfsMemo(nums, target)
            case "DP_F":
                return self.SolveDpF(nums, target)
            case _:
                raise NotImplementedError

    # dfs(i, c) = dfs(i-1, c) + dfs(i-1, c - w[i])
    def SolveDfsMemo(self, nums: List[int], target: int) -> int:
        n = len(nums)
        # 计算背包大小
        s = sum(nums) - abs(target)
        if s < 0 or s % 2 == 1:
            return 0
        capacity = s // 2

        @cache
        def dfs(i: int, c: int) -> int:
            if i < 0:  # 边界条件 NOTE: 如果 c==0 则可行方案 + 1
                return 1 if c == 0 else 0
            # 物品体积大于剩余容量, 肯定不能选
            # 跟枚举哪一个中返回 0 不同
            if nums[i] > c:
                return dfs(i - 1, c)
            return dfs(i - 1, c) + dfs(i - 1, c - nums[i])

        return dfs(n - 1, capacity)

    # f[i][c] = f[i - 1][c] + f[i - 1][c - w[i]]
    # f[i + 1][c] = f[i][c] + f[i][c - w[i]]
    def SolveDpF(self, nums: List[int], target: int) -> int:
        n = len(nums)

        # 计算背包大小
        s = sum(nums) - abs(target)
        if s < 0 or s % 2 == 1:
            return 0
        capacity = s // 2

        # 0 ~ capacity 一共 capacity + 1 个数
        f = [[0] * (capacity + 1) for _ in range(n + 1)]
        f[0][0] = 1  # 初始值

        # 递归改循环
        for i, x in enumerate(nums):  # 参数 1: i
            for c in range(capacity + 1):  # 参数 2: c
                if x > c:  # nums[i] > c一定不选
                    f[i + 1][c] = f[i][c]
                else:  # 不选/选
                    f[i + 1][c] = f[i][c] + f[i][c - x]

        return f[n][capacity]


# @leet end

if __name__ == "__main__":
    pass
