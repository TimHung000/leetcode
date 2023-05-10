from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        res, lastJumpPos, curFarthestJump, i = 0, 0, 0, 0
        while(i < len(nums) - 1):
            curFarthestJump = max(curFarthestJump, i + nums[i])
            if(i == lastJumpPos):
                res += 1
                lastJumpPos = curFarthestJump
            i += 1
        return res