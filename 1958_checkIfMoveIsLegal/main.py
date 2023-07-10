from typing import List
class Solution:
    def checkMove(self, board: List[List[str]], rMove: int, cMove: int, color: str) -> bool:
        ROWS, COLS = len(board), len(board[0])
        dir = [[1, 0], [-1, 0], [0, 1], [0, -1],
               [1, 1], [-1, -1], [1, -1], [-1, 1]]
        board[rMove][cMove] = color

        def legal(row, col, color, direction):
            row_dir, col_dir = direction
            row, col = row + row_dir, col + col_dir
            length = 1

            while( 0 <= row < ROWS and  0 <= col < COLS):
                length += 1
                if board[row][col] == ".":
                    return False
                if board[row][col] == color:
                    return length >= 3
                row, col = row + row_dir, col + col_dir
            return False
        
        for d in dir:
            if legal(rMove, cMove, color, d):
                return True
        return False