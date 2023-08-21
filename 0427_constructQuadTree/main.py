from typing import List


# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def dfs(n, row, col):
            allSame = True
            for i in range(n):
                for j in range(n):
                    if grid[row][col] != grid[row + i][col + j]:
                        allSame = False
                        break
            if allSame:
                return Node(grid[row][col], True)
            
            n = n // 2
            topleft = dfs(n, row, col)
            toprigght = dfs(n, row, col + n)
            bottomleft = dfs(n, row + n, col)
            bottomright = dfs(n, row + n, col + n)
            return Node(0, False, topleft, toprigght, bottomleft, bottomright)
        return dfs(len(grid), 0, 0)