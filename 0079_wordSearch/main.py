from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        def dfs(r, c, ith):
            if ith == len(word):
                return True
            if r < 0 or r >= len(board) or c < 0 or c >= len(board[0]) or board[r][c] != word[ith] or visited[r][c]:
                return False
                
            visited[r][c] = True
            top = dfs(r - 1, c, ith + 1)
            down = dfs(r + 1, c, ith + 1)
            left = dfs(r, c - 1, ith + 1)
            right = dfs(r, c + 1, ith + 1)
            visited[r][c] = False

            return top or down or left or right
        
        for r in range(len(board)):
            for c in range(len(board[0])):
                if dfs(r, c, 0):
                    return True
        return False