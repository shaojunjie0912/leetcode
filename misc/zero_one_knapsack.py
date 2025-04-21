from functools import cache
from typing import List


def zero_one_knapsack(capacity: int, w: List[int], v: List[int]) -> int:
    n = len(w)

    @cache
    def dfs(i, c):  # i 代表物品, c 代表容量
        # 边界条件: 没有物品了, 返回 0
        # NOTE: 如果题目求的是=capacity的可行方案, 那么这里要 return 1 if c == 0 else 0
        if i < 0:
            return 0
        if w[i] > c:  # 如果物品体积已经超过剩余容量, 一定不能选
            return dfs(i - 1, c)
        # 不选/选
        return max(dfs(i - 1, c), dfs(i - 1, c - w[i]) + v[i])

    return dfs(n - 1, capacity)
