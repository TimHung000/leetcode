from typing import List
from collections import Counter

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        perm = []
        countMap = { num: 0 for num in nums }
        for num in nums:
            countMap[num] += 1

        def backtrack():
            if len(perm) == len(nums):
                res.append(perm.copy())
                return
            
            for num in countMap:
                if countMap[num] > 0:
                    perm.append(num)
                    countMap[num] -= 1
                    backtrack()
                    countMap[num] += 1
                    perm.pop()
        
        backtrack()
        return res

class Solution1:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        counter = Counter(nums)
        def backtrack(perm):
            if len(perm) == len(nums):
                res.append(perm)
                return
            for key in counter:
                if counter[key]:
                    counter[key] -= 1
                    backtrack(perm + [key])
                    counter[key] += 1
        backtrack([])
        return res

Solution1().permuteUnique([1, 1, 2])