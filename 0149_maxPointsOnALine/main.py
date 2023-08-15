from typing import List
import collections


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 2:
            return len(points)
        
        res = 0
        for i in range(len(points)):
            countMap = collections.defaultdict(int,)
            for j in range(i + 1, len(points)):
                y = points[i][1] - points[j][1]
                x = points[i][0] - points[j][0]
                slope = y / x if x != 0 else float('inf')

                countMap[slope] += 1
                res = max(res, countMap[slope] + 1)
        return res                
