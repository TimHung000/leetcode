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

    def checkValidString2(self, s: str) -> bool:
        dp = {(len(s), 0): True}
        def dfs(i, count):
            if i == len(s) or count < 0:
                return count == 0
            
            if (i, count) in dp:
                return dp[(i, count)]

            if s[i] == '(':
                dp[(i, count)] = dfs(i+1, count+1)
            elif s[i] == ')':
                dp[(i, count)] = dfs(i+1, count-1)
            else:
                dp[(i, count)] = dfs(i+1, count+1) or dfs(i+1, count-1) or dfs(i+1, count)
            return dp[(i, count)]
        return dfs(0, 0)