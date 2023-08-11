from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        idx = 0
        while idx < len(intervals) and newInterval[0] > intervals[idx][1]:
            res.append(intervals[idx])
            idx += 1
        
        while idx < len(intervals) and newInterval[1] >= intervals[idx][0]:
            newInterval[0] = min(intervals[idx][0], newInterval[0])
            newInterval[1] = max(intervals[idx][1], newInterval[1])
            idx += 1
        res.append(newInterval)

        while idx < len(intervals):
            res.append(intervals[idx])
            idx += 1
        
        return res
    
class Solution1:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        
        for interval in intervals:
            if newInterval[0] > interval[1]:
                res.append(interval)
            elif newInterval[1] < interval[0]:
                res.append(newInterval)
                newInterval = interval
            elif newInterval[0] <= interval[1] or newInterval[1] >= interval[0]:
                newInterval[0] = min(interval[0], newInterval[0])
                newInterval[1] = max(interval[1], newInterval[1])
        res.append(newInterval)
        return res
    
class Solution2:
    def insert(self, intervals, newInterval):
        START, END = 0, 1
        s, e = newInterval[START], newInterval[END]
        left, right = [], []
        for cur_interval in intervals:
            if cur_interval[END] < s:
                left += [ cur_interval ]
            elif cur_interval[START] > e:
                right += [ cur_interval ]
            else:
                s = min(s, cur_interval[START])
                e = max(e, cur_interval[END])
                
        return left + [ [s, e] ] + right   


        
