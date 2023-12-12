from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set()
        for word in wordDict:
            wordSet.add(word)
        
        dp = [False] * len(s)

        for i in range(len(s)):
            for j in range(i+2):
                if s[j:i+1] in wordSet and (j - 1 < 0 or dp[j-1] is True):
                    dp[i] = True
                    break

        return dp[len(s)-1]

# time limit exceed
class Solution1:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set()
        memo = {}
        for word in wordDict:
            wordSet.add(word)

        def canMatch(startIdx: int):
            if startIdx == len(s):
                return True
            for i in range(startIdx+1, len(s)+1):
                if s[startIdx:i] in wordSet:
                    if i in memo and memo[i] is True:
                        memo[startIdx] = True
                        return True
                    
                    if i not in memo and canMatch(i) is True:
                        memo[startIdx] = True
                        return True
            
            return False
        
        return canMatch(0)

if __name__ == "__main__":
    print(Solution().wordBreak("catsandog", ["cats","dog","sand","and","cat"]))