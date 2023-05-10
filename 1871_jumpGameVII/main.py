from collections import deque

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        myQueue = deque([0])
        farthestJump = 0

        while myQueue:
            curPos = myQueue.popleft()
            start = max(curPos + minJump, farthestJump + 1)
            end = min(curPos + maxJump + 1, len(s))
            for i in range(start, end):
                if s[i] == '0':
                    if i == len(s) - 1:
                        return True
                    myQueue.append(i)
            farthestJump = curPos + maxJump
        
        return False
                    
