from typing import List
from collections import defaultdict

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        count = defaultdict(int)
        l, res = 0, 0
        for r in range(len(fruits)):
            count[fruits[r]] += 1

            while len(count) > 2:
                count[fruits[l]] -= 1
                if count[fruits[l]] == 0:
                    count.pop(fruits[l])
                l += 1
            
            res = max(res, r - l + 1)
        return res

