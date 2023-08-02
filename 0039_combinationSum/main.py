from typing import List
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        subset = []
        def dfs(startIdx, target):
            if startIdx >= len(candidates):
                return
            if target < 0:
                return
            if target == 0:
                res.append(subset[:])
                return
            
            subset.append(candidates[startIdx])
            dfs(startIdx, target - candidates[startIdx])

            subset.pop()
            dfs(startIdx + 1, target)
        
        dfs(0, target)
        return res
    
class Solution1:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        def dfs(cur, cur_sum, idx):
            if cur_sum > target:
                return
            if cur_sum == target:
                res.append(cur)
                return
            
            for i in range(idx, len(candidates)):
                dfs(cur + [candidates[i]], cur_sum + candidates[i], i)
            
        dfs([], 0, 0)
        return res
    
class Solution2:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ways_hash = [ [] for index in range(0, target + 1)]
        ways_hash[0] = [[]]
        
        for candidate in candidates:
            for index in range(candidate, len(ways_hash)):
                for combo in ways_hash[index - candidate]:
                    newCombo = combo + [candidate]
                    ways_hash[index].append(newCombo)

        return ways_hash[target]

        