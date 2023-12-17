from typing import List
import heapq
from collections import deque

class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        pass 

class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        res = []
        queue = [(task[0], idx) for idx, task in enumerate(tasks)]
        queue.sort()
        queue = deque(queue)
        minHeap = []
        curTime = 0 
        while minHeap or queue:
            while queue and curTime >= queue[0][0]:
                startTime, idx = queue.popleft()
                heapq.heappush(minHeap, (tasks[idx][1], idx))

            if not minHeap and queue:
                curTime = queue[0][0]
                while queue and curTime >= queue[0][0]:
                    startTime, idx = queue.popleft()
                    heapq.heappush(minHeap, (tasks[idx][1], idx))
            
            processingTime, idx = heapq.heappop(minHeap)
            res.append(idx)
            curTime += processingTime

        return res
    
if __name__ == "__main__":
    print(Solution().getOrder([[1,2],[2,4],[3,2],[4,1]]))