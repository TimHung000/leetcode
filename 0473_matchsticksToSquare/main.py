from typing import List

class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        length = sum(matchsticks) // 4
        sides = [0] * 4

        if sum(matchsticks) / 4 != length:
            return False
        
        matchsticks.sort(reverse=True)

        def backtrack(idx):
            if idx == len(matchsticks):
                return True
            
            for i in range(4):
                if sides[i] + matchsticks[idx] <= length:
                    sides[i] += matchsticks[idx]
                    if backtrack(idx+1):
                        return True
                    sides[i] -= matchsticks[idx]
            return False