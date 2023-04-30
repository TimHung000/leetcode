from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(_grid: List[List[bool]],i:int, j:int):
            if i < 0 or i >= len(_grid) or j < 0 or j >= len(_grid[0]):
                return
            if _grid[i][j] == False and grid[i][j] == '1':
                _grid[i][j] = True
                dfs(_grid, i, j-1)
                dfs(_grid, i+1, j)
                dfs(_grid, i, j+1)
                dfs(_grid, i-1, j)

        _grid = [[False for i in row] for row in grid]

        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if _grid[i][j] == False and grid[i][j] == '1':
                    dfs(_grid, i, j)
                    res += 1

        return res

if __name__ == "__main__":
    grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
    sol = Solution()
    sol.numIslands(grid)
                    
