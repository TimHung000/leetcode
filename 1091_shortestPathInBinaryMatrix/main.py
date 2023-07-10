from typing import List
from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        N = len(grid)
        q = deque([(0, 0, 1)]) # row, col, length
        visited = set((0, 0))
        direct = [[0, 1], [1, 0], [0, -1], [-1, 0],
                  [1, 1], [-1, -1], [1, -1], [-1, 1]]
        while q:
            row, col, length = q.popleft()
            if row < 0 or col < 0 or row >= N or col >= N or grid[row][col]:
                continue

            if row == N - 1 and col == N - 1:
                return length
            
            for dr, dc in direct:
                if (row + dr, col + dc) not in visited:
                    q.append((row + dr, col + dc, length + 1))
                    visited.add((row + dr, col + dc))
        return -1
