class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        reverse_s = s[::-1]
        
        dp=[[0 for _ in range(len(s)+1)] for __ in range(len(s)+1)]
        
        for i in range(1, len(s) + 1): 
            for j in range(1, len(s) + 1):
                if s[i-1] != reverse_s[j-1]:
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j])
                else:
                    dp[i][j] = 1 + dp[i-1][j-1]
        return dp[-1][-1]

class Solution1:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        
        for i in range(n):
            dp[i][i] = 1
            
        # Iterate over substrings of length 2 to n
        for l in range(2, n+1):
            for i in range(n-l+1):
                j = i + l - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        
        return dp[0][n-1]
    
