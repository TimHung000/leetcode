from typing import List
import heapq
class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        intervals.sort()
        queries_sorted = sorted((query, idx) for idx, query in enumerate(queries))

        minHeap = []
        res = [-1 for _ in range(len(queries))]
        i = 0
        for query, idx in queries_sorted:
            while i < len(intervals):
                l, r = intervals[i]
                if l > query:
                    break
                heapq.heappush(minHeap, (r - l + 1, r))
                i += 1

            while minHeap and minHeap[0][1] < query:
                heapq.heappop(minHeap)
            
            res[idx] = minHeap[0][0] if minHeap else -1

        return res
    