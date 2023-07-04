from typing import List
import collections

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        def label_to_position(label):
            row = (label - 1) // n
            col = (label - 1) % n
            if(row % 2 == 0):
                return n-1-row, col
            else:
                return n-1-row, n-1-col
        
        visited = set()
        myQueue = collections.deque()
        myQueue.append((1, 0)) # start position
        while myQueue:
            label, step = myQueue.popleft()
            row, col = label_to_position(label)
            if board[row][col] != -1:
                label = board[row][col]
            if label == n*n:
                return step
            
            for i in range(1, 7):
                next_label = label + i
                if next_label <= n*n and next_label not in visited:
                    visited.add(next_label)
                    myQueue.append((next_label, step+1))
        return -1

test = [[-1,-1],[-1,3]]
sol = Solution()
sol.snakesAndLadders(test)
