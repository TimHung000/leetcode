from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        def dfs(startIdx: int, comb):
            if len(comb) == k:
                res.append(comb[:])
                return

            for i in range(startIdx, n + 1):
                comb.append(i)
                dfs(i+1, comb)
                comb.pop()
        dfs(1, [])
        return res
