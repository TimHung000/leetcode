from typing import List
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        if total % k:
            return False
        target = total // k
        subsets = [0] * k
        nums.sort(reverse=True)

        def backtrack(i):
            if i == len(nums):
                return True
            
            for j in range(k):
                if subsets[j] + nums[i] <= target:
                    subsets[j] += nums[i]
                    if backtrack(i + 1):
                        return True
                    subsets[j] -= nums[i]

                    """
                    Explanation:
                    If subSets[j] = 0, it means this is the first time adding values to that subset.
                    If the backtrack search fails when adding the values to subSets[j] and subSets[j] remains 0, it will also fail for all subSets from subSets[j+1:].
                    Because we are simply going through the previous recursive tree again for a different j+1 position.
                    So we can effectively break from the for loop or directly return False.
                    """
                    if subsets[j] == 0:
                        break
            return False
        return backtrack(0)
    
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        if len(nums) < k or total % k:
            return False
        nums.sort(reverse=True)
        target = total // k
        if nums[0] > target:
            return False
        
        selected = [False] * len(nums)        
        def backtrack(i, k, curSum):
            if k == 0:
                return True
            if curSum > target:
                return False
            elif curSum == target:
                return backtrack(0, k - 1, 0)
            
            for j in range(i, len(nums)):
                if not selected[j]:
                    selected[j] = True
                    if backtrack(j + 1, k, curSum + nums[j]):
                        return True
                    selected[j] = False
            return False
        return backtrack(0, k, 0)
