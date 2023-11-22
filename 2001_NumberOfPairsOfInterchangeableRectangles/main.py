from typing import List

class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        count = {}
        res = 0
        for i in range(len(rectangles)-1, -1, -1):
            ratio = rectangles[i][0] / rectangles[i][1]
            if ratio in count:
                res += count[ratio]
                count[ratio] += 1
            else:
                count[ratio] = 1

        return res
        