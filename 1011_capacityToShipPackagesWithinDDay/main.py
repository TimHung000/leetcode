from typing import List

class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l, r = max(weights), sum(weights)

        while l < r:
            m = (l + r) // 2
            cur = 0
            daysNeeded = 1
            for w in weights:
                if cur + w > m:
                    daysNeeded += 1
                    cur = 0
                cur += w
            if daysNeeded > days:
                l = m + 1
            else:
                r = m
        return l

