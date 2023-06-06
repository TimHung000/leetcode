from collections import deque

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        radiant, dire = deque(), deque()
        senateLen = len(senate)
        for idx, c in enumerate(senate):
            if c == 'R':
                radiant.append(idx)
            else:
                dire.append(idx)
        
        while radiant and dire:
            radiantFront = radiant.popleft()
            direFront = dire.popleft()
            if radiantFront < direFront:
                radiant.append(radiantFront + senateLen)
            else:
                dire.append(direFront + senateLen)
        
        return "Radiant" if radiant else "Dire"
