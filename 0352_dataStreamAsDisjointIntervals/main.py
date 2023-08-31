from typing import List
from sortedcontainers import SortedList
class SummaryRanges:

    def __init__(self):
        self.intervals = SortedList()
        

    def addNum(self, value: int) -> None:
        n = len(self.intervals)
        idx = self.intervals.bisect_right((value, float("inf")))
        
        lTree = self.intervals[idx-1] if 0 <= idx-1 < n else (float("-inf"), float("-inf"))
        rTree = self.intervals[idx] if 0 <= idx < n else (float("inf"), float("inf"))

        if lTree[0] <= value <= lTree[1]:
            return
        
        l, r = value, value
        if lTree[1] + 1 == value:
            self.intervals.remove(lTree)
            l = lTree[0]
        
        if rTree[0] - 1 == value:
            self.intervals.remove(rTree)
            r = rTree[1]
        
        self.intervals.add((l, r))

    def getIntervals(self) -> List[List[int]]:
        return self.intervals


# Your SummaryRanges object will be instantiated and called as such:
def exe(obj, method, value):
    if method == "addNum":
        obj.addNum(value[0])
    if method == "getIntervals":
        obj.getIntervals()

obj = SummaryRanges()
method = ["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]
value = [[],[6],[],[6],[],[0],[],[4],[],[8],[],[7],[],[6],[],[4],[],[7],[],[5],[]]
for i in range(1, len(method)):
    exe(obj, method[i], value[i])
    print(obj.intervals)
