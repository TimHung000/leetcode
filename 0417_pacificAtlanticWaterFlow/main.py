from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return []

        pacific = set()
        atalantic = set()

        def dfs(row, col, land):
            land.add((row, col))
            for i, j in [(row+1, col), (row, col+1), (row-1, col), (row, col-1)]:
                if (0 <= i < len(heights) and 0 <= j < len(heights[0]) and heights[i][j] >= heights[row][col] and (i, j) not in land):
                    dfs(i, j, land)
                    
        for i in range(len(heights)):
            dfs(i, 0, pacific)
            dfs(i, len(heights[0])-1, atalantic)

        for j in range(len(heights[0])):
            dfs(0, j, pacific)
            dfs(len(heights)-1, j, atalantic)

        return list(pacific & atalantic)
                