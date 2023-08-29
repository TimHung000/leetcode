from typing import List
import heapq

class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        res = float("inf")
        minNum = float("inf")
        maxHeap = []
        for num in nums:
            if num % 2 == 1:
                num *= 2
            heapq.heappush(maxHeap, -num)
            minNum = min(minNum, num)
        
        while -maxHeap[0] % 2 == 0:
            num = -heapq.heappop(maxHeap)
            res = min(res, num - minNum)
            minNum = min(minNum, num // 2)
            heapq.heappush(maxHeap, -(num // 2))
        res = min(res, -maxHeap[0] - minNum)
        return res
