from typing import List
from collections import defaultdict

class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        myMap = defaultdict(int)

        for rowList in wall:
            pos = 0
            for val in rowList[:-1]:
                pos += val
                myMap[pos] += 1
        
        maxCount = 0
        for _, count in myMap.items():
            maxCount = max(maxCount, count)
        res = len(wall) - maxCount
        return res