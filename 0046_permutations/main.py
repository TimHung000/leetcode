from typing import List
from collections import deque
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        used = [False] * len(nums)
        permutation = []
        def backtrack():
            if len(permutation) == len(nums):
                res.append(permutation[:])
                return
            for i in range(len(nums)):
                if not used[i]:
                    used[i] = True
                    permutation.append(nums[i])
                    backtrack()
                    used[i] = False
                    permutation.pop()
        backtrack()
        return res
    

class Solution1:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) <= 1:
            return [nums]

        res = []
        queue = deque([([], nums)])

        while queue:
            arr, options = queue.popleft()

            for i in range(len(options)):
                next_options = options[:i] + options[i+1:]
                new_arr = arr + [options[i]]

                if next_options:
                    queue.append((new_arr, next_options))
                else:
                    res.append(new_arr)
        return res

class Solution2:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def dfs(startIdx):
            if startIdx == len(nums):
                res.append(nums[:])
            
            for i in range(startIdx, len(nums)):
                nums[i], nums[startIdx] = nums[startIdx], nums[i]
                dfs(startIdx + 1)
                nums[startIdx], nums[i] = nums[i], nums[startIdx]
        dfs(0)
        return res