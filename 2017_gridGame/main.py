from typing import List

class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        N = len(grid[0])
        prefixSum1 = [val for val in grid[0]]
        prefixSum2 = [val for val in grid[1]]

        for i in range(1, N):
            prefixSum1[i] += prefixSum1[i-1]
            prefixSum2[i] += prefixSum2[i-1]
        
        res = float("inf")
        for i in range(N):
            row1 = prefixSum1[-1] - prefixSum1[i]
            row2 = prefixSum2[i-1] if i > 0 else 0
            robot2PathSum = max(row1, row2)
            res = min(res, robot2PathSum)

        return res
             
if __name__ == "__main__":
    print(Solution().gridGame([[1,3,1,15],[1,3,3,1]]))

