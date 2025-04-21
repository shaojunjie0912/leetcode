from typing import List, Dict, Tuple
from functools import cache

# 「爬楼梯」
# 每次可以爬 1/2 个台阶: dfs(i) = dfs(i-1) + dfs(i-2)
# 本题可类比爬楼梯, 因为顺序不同的序列是不同组合
# 每次可以爬 nums[i] 个台阶
# dfs(i): 爬 i 个台阶的方案数
# dfs(i) = sum(dfs(i - nums[j])) nums[j] <= i


# @leet start
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        @cache
        def dfs(i: int) -> int:
            if i == 0:  # 爬 0 个台阶方案数为: 1
                return 1
            # NOTE: 爬 i 个台阶时, 只选 step <= i 的
            return sum(dfs(i - step) for step in nums if step <= i)

        return dfs(target)


# @leet end

if __name__ == "__main__":
    pass
