from typing import List

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        res: int 
        while l <= r:
            # m = (l + r) // 2  possible overflow
            m = l + ((r - l) // 2)

            if (m - 1 < 0 or nums[m - 1] != nums[m]) and (m + 1 == len(nums) or nums[m] != nums[m + 1]):
                res = nums[m]
                break

            if m > 0 and nums[m - 1] == nums[m]:
                leftSize = m - 1
            else:
                leftSize = m
            
            if leftSize % 2 == 0:
                l = m + 1
            else:
                r = m - 1

        return res
            