from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        intervals.sort(key = lambda i : i[0])
        prev = intervals[0]
        for interval in intervals[1:]:
            if prev[1] < interval[0]:
                res.append(prev)
                prev = interval
            else:
                prev[1] = max(interval[1], prev[1])

        res.append(prev)
        return res
    
class Solution1:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda i: i[0])
        res = [intervals[0]]

        for interval in intervals[1:]:
            if res[-1][1] < interval[0]:
                res.append(interval)
            else:
                res[-1][1] = max(res[-1][1], interval[1])
        
        return res