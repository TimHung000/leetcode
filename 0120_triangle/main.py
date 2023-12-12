from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [[triangle[i][j] for j in range(len(triangle[i]))] for i in range(len(triangle))]

        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                dp[i][j] += min(dp[i+1][j], dp[i+1][j+1])
        return dp[0][0]

# time limit exceeded
class Solution1:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        depth = len(triangle)
        res = float('inf')
        stack = []
        cur = (0, 0, 0) # nextI, nextJ, prevLength
        while stack or cur:
            i, j, prevLen = cur
            while i < depth:
                stack.append((i, j, prevLen))
                prevLen += triangle[i][j]
                i += 1
            res = min(res, prevLen)
            if not stack:
                break
            i, j, prevLen = stack.pop()
            cur = i + 1, j + 1, prevLen + triangle[i][j]

        return res

if __name__ == "__main__":
    print(Solution().minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]]))