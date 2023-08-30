from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        ROW, COL = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0 for _ in range(COL)] for _ in range(ROW)]

        dp[0][0] = 1 if obstacleGrid[0][0] != 1 else 0
        for r in range(ROW):
            for c in range(COL):
                if obstacleGrid[r][c] == 1:
                    continue
                if r > 0:
                    dp[r][c] += dp[r-1][c]
                if c > 0:
                    dp[r][c] += dp[r][c-1]
        return dp[-1][-1]