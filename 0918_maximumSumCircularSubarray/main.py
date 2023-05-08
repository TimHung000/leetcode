class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        curmax = 0
        curmin = 0
        total = 0
        globalmax = nums[0]
        globalmin = nums[0]
        for num in nums:
            curmax = max(curmax + num, num)
            curmin = min(curmin + num, num)
            total += num
            globalmax = max(curmax, globalmax)
            globalmin = min(curmin, globalmin)
        
        return max(globalmax, total - globalmin) if globalmax >= 0 else globalmax