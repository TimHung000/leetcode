from typing import List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        minHeap = []
        for i, num in enumerate(nums):
            heapq.heappush(minHeap, num)
            if i >= k:
                heapq.heappop(minHeap)

        return heapq.heappop(minHeap)