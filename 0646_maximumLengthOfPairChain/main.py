from typing import List

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        sorted_pairs = sorted(pairs, key= lambda pair: (pair[1], pair[0]))
        length = 1
        end = sorted_pairs[0][1]
        for i in range(1, len(sorted_pairs)):
            if end < sorted_pairs[i][0]:
                length += 1
                end = sorted_pairs[i][1]

        return length
    
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        sorted_pairs = sorted(pairs, key=lambda x: x[0])
        dp = [1] * len(sorted_pairs)
        res = 1
        for i in range(1, len(sorted_pairs)):
            for j in range(i):
                if sorted_pairs[i][0] > sorted_pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
                    res = max(res, dp[i])
        return res