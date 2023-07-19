from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = 0
        r = 1
        while r < len(nums):
            if nums[l] == nums[r]:
                r += 1
                continue
            else:
                l += 1
                nums[l] = nums[r]
        return l + 1
    
    def removeDuplicates1(self, nums: List[int]) -> int:
        nums[:] = sorted(set(nums))
        return len(nums)
    
    def removeDuplicates2(self, nums: List[int]) -> int:
        i = 1
        while i < len(nums):
            if nums[i] == nums[i-1]:
                nums.pop(i)
            else:
                i += 1
        return len(nums)

test = [1,1,2]

Solution().removeDuplicates(test)