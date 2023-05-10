from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        last = len(nums) - 1
        can_reach = 0
        i = 0
        while i <= can_reach:
            if i >= last:
                return True
            can_reach = max(i + nums[i], can_reach)
            i += 1
        return False