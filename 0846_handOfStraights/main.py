from typing import List

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False

        # map
        count = {}
        for val in hand:
            count[val] = 1 + count.get(val, 0)

        # min heap
        minHeap = list(count.keys())
        heapq.heapify(minHeap)
        while minHeap:
            first = minHeap[0]
            for i in range(first, first + groupSize):
                if i not in count:
                    return False
                count[i] -= 1
                if count[i] == 0:
                    # the next round won't be able to form a group
                    if i != minHeap[0]:
                        return False
                    heapq.heappop(minHeap)
        return True
        