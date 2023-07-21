from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        if k > len(arr):
            return -1
        res = 0
        threshold *= k
        total = sum(arr[0:k-1])
        for r in range(k-1, len(arr)):
            total += arr[r]
            if total >= threshold:
                res += 1
            total -= arr[r-k+1]
        return res
        

