class Solution:
    def checkValidString(self, s: str) -> bool:
        minCount, maxCount = 0, 0

        for c in s:
            if c == '(':
                minCount += 1
                maxCount += 1
            if c == ')':
                minCount -= 1
                maxCount -= 1
            if c == '*':
                minCount -= 1
                maxCount += 1
            
            if maxCount < 0:
                return False
            if minCount < 0: # required s = (*)(
                minCount = 0
        return minCount == 0
