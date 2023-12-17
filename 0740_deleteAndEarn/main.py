from typing import List
from collections import Counter

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        count = Counter(nums)
        nums = sorted(list(set(nums)))

        earn1, earn2 = 0, 0
        for i in range(len(nums)):
            curEarn = nums[i] * count[nums[i]]

            if i > 0 and nums[i] == nums[i-1] + 1:
                tmp = earn2
                earn2 = max(curEarn + earn1, earn2)
                earn1 = tmp
            else:
                tmp = earn2
                earn2 = curEarn + earn2
                earn1 = tmp
        return earn2

class Solution1:
    def deleteAndEarn(self, nums: List[int]) -> int:
        count = Counter(nums)
        nums = sorted(list(set(nums)))
        dp = [0] * (len(nums) + 2)
        for i in range(len(nums)):
            curEarn = nums[i] * count[nums[i]]
            if nums[i] == nums[i-1] + 1:
                dp[i+2] = max(curEarn + dp[i], dp[i+1])
            else:
                dp[i+2] = curEarn + dp[i+1]
        return dp[len(nums)+1]
    
class Solution2:
    def deleteAndEarn(self, nums: List[int]) -> int:
        sNum = sorted(nums)
        count = {}
        distinct = []
        for num in sNum:
            count[num] = count.get(num, 0) + 1
            if not distinct or distinct[-1] != num:
                distinct.append(num)

        dp = [-1] * len(nums)

        def dfs(idx):
            if idx >= len(distinct):
                return 0
            
            if dp[idx] != -1:
                return dp[idx]
            
            chosed = distinct[idx] * count[distinct[idx]]
            if idx + 1 < len(distinct) and distinct[idx + 1] == distinct[idx] + 1:
                chosed += dfs(idx + 2)
            else:
                chosed += dfs(idx + 1)

            notChosed = dfs(idx + 1)

            dp[idx] = max(chosed, notChosed)
            return dp[idx]
        
        return dfs(0)


if __name__ == "__main__":
    print(Solution().deleteAndEarn([3,4,2]))