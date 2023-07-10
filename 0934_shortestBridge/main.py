from typing import List
from collections import deque

class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        N = len(grid)
        direct = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        def invalid(row, col):
            return row < 0 or col < 0 or row >= N or col >= N
        
        visited = set()
        def dfs(row, col):
            if invalid(row, col) or not grid[row][col] or (row, col) in visited:
                return
            visited.add((row, col))
            for row_dir, col_dir in direct:
                dfs(row + row_dir, col + col_dir)

        def bfs():
            res = 0
            q = deque(visited)
            while q:
                length = len(q)
                for i in range(length):
                    row , col = q.popleft()
                    for row_dir, col_dir in direct:
                        curR, curC = row + row_dir, col + col_dir
                        if invalid(curR, curC) or (curR, curC) in visited:
                            continue
                        if grid[curR][curC]:
                            return res
                        q.append((curR, curC))
                        visited.add((curR, curC))
                res += 1
        
        for row in range(N):
            for col in range(N):
                if grid[row][col]:
                    dfs(row, col)
                    return bfs()
        

grid = [[0,1],[1,0]]
sol = Solution()
sol.shortestBridge(grid)