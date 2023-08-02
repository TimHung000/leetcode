from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def backtrack(startIdx, subset):
            if startIdx == len(nums):
                res.append(subset[:])
                return
            
            # All subsets that include nums[i]
            subset.append(nums[startIdx])
            backtrack(startIdx + 1, subset)
            subset.pop()

            # All subsets that don't include nums[i]
            while startIdx + 1 < len(nums) and nums[startIdx] == nums[startIdx + 1]:
                startIdx += 1
            backtrack(startIdx + 1, subset)

        backtrack(0, [])
        return res
    
class Solution1:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def backtrack(startIdx, subset):
            res.append(subset[:])
            for i in range(startIdx, len(nums)):
                if i > startIdx and nums[i] == nums[i-1]:
                    continue
                subset.append(nums[i])
                backtrack(i + 1, subset)
                subset.pop()
        
        backtrack(0, [])
        return res
