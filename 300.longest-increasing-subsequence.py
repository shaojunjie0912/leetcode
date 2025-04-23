from typing import List, Dict, Tuple, Literal
from functools import cache
from math import inf


# @leet start
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        method: Literal["DFS_MEMO"] = "DFS_MEMO"
        match method:
            case "DFS_MEMO":
                return self.SolveDfsMemo(nums)

    # dfs(i) = max{dfs(j)} + 1, j < i && nums[j] < nums[i]
    def SolveDfsMemo(self, nums: List[int]) -> int:
        n = len(nums)

        @cache
        def dfs(i: int) -> int:
            res = 0
            for j in range(i):  # 枚举小于 i 的 j
                if nums[j] < nums[i]:  # 如果 nums[j] < nums[i] 则继续递归
                    res = max(res, dfs(j))
            return res + 1  # + 1 表示 i

        return max(dfs(i) for i in range(n))  # 遍历整个数组递归


# @leet end

if __name__ == "__main__":
    pass
