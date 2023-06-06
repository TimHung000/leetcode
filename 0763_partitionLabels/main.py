class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        res = []
        lastIdx = dict()
        for idx, char in enumerate(s):
            lastIdx[char] = idx
        
        currentEnd = 0
        currentStart = 0
        for i in range(len(s)):
            currentEnd = max(currentEnd, lastIdx[s[i]])
            if(i == currentEnd):
                res.append(currentEnd-currentStart+1)
                currentStart = currentEnd + 1
        return res