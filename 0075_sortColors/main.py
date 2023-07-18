from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        # use the concept of quick sort partition
        l, r = 0, len(nums)-1 # left ptr for 0; right ptr for 2
        i = 0 # iterator

        while i <= r:
            if nums[i] == 0:
                nums[i], nums[l] = nums[l], nums[i]
                l +=1
            
            elif nums[i] == 2:
                nums[i], nums[r] = nums[r], nums[i]
                r -= 1
                # 0 1 2 1 0 2
                #   ^ ^   ^
                #   l i   r
                # In this case, if we swap i and r without stop the increment of i, 
                # it will cause the ans to be wrong
                i -= 1

            i += 1
