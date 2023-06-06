import math

class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        res = nums[0]
        total = nums[0]
        for i in range(1, len(nums)):
            total += nums[i]
            res = max(res, math.ceil(total / (i+1)))
        return res