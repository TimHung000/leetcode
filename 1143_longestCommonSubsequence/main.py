class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1, len2 = len(text1), len(text2)
        dp = [[0 for _ in range(len2)] for _ in range(len1)]

        for i in range(len1):
            for j in range(len2):
                if text1[i] == text2[j]:
                    tmp = dp[i-1][j-1] if i > 0 and j > 0 else 0
                    dp[i][j] = tmp + 1
                else:
                    tmp1 = dp[i-1][j] if i > 0 else 0
                    tmp2 = dp[i][j-1] if j > 0 else 0
                    dp[i][j] = max(tmp1, tmp2)

        return dp[-1][-1]
    