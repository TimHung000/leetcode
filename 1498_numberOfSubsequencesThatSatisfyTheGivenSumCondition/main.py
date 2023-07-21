from typing import List

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort() 
        res = 0
        mod = (10**9 + 7)

        l = 0
        r = len(nums) - 1
        while l < len(nums):
            while (nums[l] + nums[r]) > target and l <= r:
                r -= 1
            if l <= r:
                res += (2**(r-l))
            l += 1

        return res % mod

