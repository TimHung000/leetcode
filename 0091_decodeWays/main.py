class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0
        
        dp = [0] * (len(s) + 1)
        dp[0] = dp[1] = 1
        for i in range(2, len(s) + 1):
            if int(s[i-1]) >= 1 and int(s[i-1]) <= 9:
                dp[i] += dp[i-1]
            
            if int(s[i-2] + s[i-1]) >= 10 and int(s[i-2] + s[i-1]) <= 26:
                dp[i] += dp[i-2]
        
        return dp[-1]

class Solution1:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0
        
        dp = [0 for _ in range(len(s)+1)]
        dp[0] = 1
        for i in range(1, len(s) + 1):
            if s[i-1] != '0':
                dp[i] = dp[i-1]
            
            if i >= 2:
                tmp = int(s[i-2: i])
                if 10 <= tmp <= 26:
                    dp[i] += dp[i-2]
        
        return dp[len(s)]