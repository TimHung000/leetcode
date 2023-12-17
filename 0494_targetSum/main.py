from typing import List

class Solution1:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {}

        def dfs(idx, curSum):
            if (idx, curSum) in dp:
                return dp[(idx, curSum)]
            if idx == len(nums) and curSum == target:
                return 1
            if idx >= len(nums):
                return 0
            
            res = 0
            res += dfs(idx + 1, curSum - nums[idx])
            res += dfs(idx + 1, curSum + nums[idx])
            dp[(idx, curSum)] = res
            return res
        
        return dfs(0, 0)