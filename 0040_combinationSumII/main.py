from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtrack(startIdx, target, subset):
            if target < 0:
                return
            
            if target == 0:
                res.append(subset[:])
                return
            
            for i in range(startIdx, len(candidates)):
                if i > startIdx and candidates[i] == candidates[i-1]:
                    continue
                subset.append(candidates[i])
                backtrack(i + 1, target - candidates[i], subset)
                subset.pop()

        backtrack(0, target, [])
        return res
    
class Solution1:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtrack(startIdx, target, subset):
            if target == 0:
                res.append(subset[:])
                return
            
            if startIdx >= len(candidates) or target < 0:
                return
            
            subset.append(candidates[startIdx])
            backtrack(startIdx + 1, target - candidates[startIdx], subset)
            subset.pop()

            while startIdx + 1 < len(candidates) and candidates[startIdx] == candidates[startIdx + 1]:
                startIdx += 1
            backtrack(startIdx + 1, target, subset)

        backtrack(0, target, [])
        return res    

