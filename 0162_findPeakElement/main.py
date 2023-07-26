from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        res = -1
        while l <= r:
            m = (l + r) // 2
            # left neighbor greater
            if m > 0 and nums[m] < nums[m-1]:
                r = m - 1
            # right neighbor greater
            elif m < len(nums)-1 and nums[m] < nums[m+1]:
                l = m + 1
            else:
                res = m
                break
        return res
            
