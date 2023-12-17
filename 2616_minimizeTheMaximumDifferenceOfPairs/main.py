from typing import List

class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        def isValid(threshold):
            i, cnt = 0, 0
            while i < len(nums) - 1:
                if abs(nums[i] - nums[i + 1]) <= threshold:
                    cnt += 1
                    i += 2
                else:
                    i += 1

                if cnt == p:
                    return True
            return False
        
        if p == 0:
            return 0
        
        nums.sort()
        l, r = 0, nums[-1] - nums[0]
        while l < r:
            m = l + (r - l) // 2
            if isValid(m):
                r = m
            else:
                l = m + 1

        return l
# dp
# Memort Limit exceeded
class Solution1:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        if p == 0:
            return 0
        
        nums.sort()
        dp = [[float('inf') for _ in range(p + 1)] for _ in range(len(nums))]
        for i in range(len(nums)):
            dp[i][0] = 0
        dp[1][1] = abs(nums[1] - nums[0])

        for i in range(2, len(nums)):
            for j in range(1, p + 1):
                if j * 2 > i + 1:
                    break
                
                tmp1 = dp[i-1][j]
                tmp2 = max(abs(nums[i] - nums[i-1]), dp[i-2][j-1])
                dp[i][j] = min(tmp1, tmp2)

        return dp[len(nums)-1][p]

# time limit exceeded
class Solution2:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        dp = [[-1 for _ in range(p + 1)] for _ in range(len(nums))]


        def dfs(i, p):
            if p == 0:
                return 0
            
            if i >= len(nums) - 1:
                return float('inf')
            
            if dp[i][p] != -1:
                return dp[i][p]
            
            tmp1 = dfs(i + 1, p) # not include (nums[i], nums[i+1])
            tmp2 = max(abs(nums[i] - nums[i + 1]), dfs(i + 2, p - 1)) # include (nums[i], nums[i+1])
            dp[i][p] = min(tmp1, tmp2)
            return dp[i][p]
        
        return dfs(0, p)
    
if __name__ == "__main__":
    print(Solution1().minimizeMax([0,5,3,4], 0))