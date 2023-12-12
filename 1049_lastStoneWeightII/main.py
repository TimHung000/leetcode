from typing import List

class Solution:
    # Divide all the number to 2 group
    # make 2 group as close a possible
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total = sum(stones)
        target = total // 2
        curMin = float('inf')
        possible = set([0])
        for stone in stones:
            newPossible = set()
            for cur in possible:
                newValue = cur + stone
                newPossible.add(newValue)
                if newValue >= target:
                    curMin = min(curMin, newValue - target)
            possible = possible.union(newPossible)

        half1 = target + curMin
        half2 = total - half1
        return abs(half1 - half2)
    

class Solution1:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        s = {0}
        for st in stones:
            tmp = set()
            for i in s:
                tmp.add(abs(i + st))
                tmp.add(abs(i - st))
            s = tmp
        return min(s) if len(s) > 0 else 0
    
class Solution2:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total = sum(stones)
        target = total // 2 + 1
        dp = [[False for _ in range(target)] for _ in range(len(stones))]

        for i in range(len(stones)):
            for j in range(target):
                if j == 0 or j == stones[i] or (i - 1 >= 0 and dp[i-1][j]) or (j - stones[i] >= 0 and dp[i-1][j - stones[i]]):
                    dp[i][j] = True
        
        # look the last row from backwards, to find the subset1
        for num in range(len(dp[-1])-1,-1,-1):
            if dp[-1][num]:
                subset1 = num
                subset2 = total - num
                return abs(subset1 - subset2)

class Solution3:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        # Memoization
        stoneSum = sum(stones)
        target = stoneSum // 2

        def dfs(i, total):
            if total >= target or i == len(stones):
                return abs(total - (stoneSum - total))
            if (i, total) in dp:
                return dp[(i, total)]

            dp[(i, total)] = min(dfs(i + 1, total),
                                 dfs(i + 1, total + stones[i]))
            return dp[(i, total)]

        dp = {}
        return dfs(0, 0)

if __name__ == "__main__":
    print(Solution2().lastStoneWeightII([31,26,33,21,40]))