from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        curMin, curMax = 1, 1
        for num in nums:
            tmp = curMax
            curMax = max(tmp * num, curMin * num, num)
            curMin = min(tmp * num, curMin * num, num)
            res = max(res, curMax, curMin)
        return res
    