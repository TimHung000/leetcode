
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        
        dp = [[False] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        dp[0][0] = True
        
        for i in range(1, len(s1) + 1):
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]
        
        for j in range(1, len(s2) + 1):
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]
        
        for i in range(1, len(s1) + 1):
            for j in range(1, len(s2) + 1):
                dp[i][j] = (dp[i-1][j] and s1[i-1] == s3[i+j-1]) or (dp[i][j-1] and s2[j-1] == s3[i+j-1])
        
        return dp[len(s1)][len(s2)]

class Solution1:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        dp = {}

        def dfs(i, j):
            if i == len(s1) and j == len(s2):
                return True
            
            if (i, j) in dp:
                return dp[(i, j)]
            
            if i < len(s1) and s1[i] == s3[i + j] and dfs(i + 1, j):
                return True
            
            if j < len(s2) and s2[j] == s3[i + j] and dfs(i, j + 1):
                return True
        
            dp[(i, j)] = False
            return False
        
        return dfs(0, 0)