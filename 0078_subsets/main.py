from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        subset = []
        def dfs(index):
            if index >= len(nums):
                res.append(subset.copy()) # or res.append(subset[:])
                return
            
            subset.append(nums[index])
            dfs(index + 1)
 
            subset.pop()
            dfs(index + 1)
            
        dfs(0)
        return res
    
class Solution1:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        def dfs(idx, curr):
            res.append(list(curr))
            # Iterating over all the elements of the array
            for i in range(idx, len(nums)):
                # Include
                curr.append(nums[i])
                # Simulate proceeding while including it
                dfs(i + 1, curr)
                # Exclude
                curr.pop()
    
        dfs(0, [])
        return res

class Solution2:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subsets = [[]]
        for n in nums:
            subsets += [s + [n] for s in subsets]
        return subsets

        ## method2
        # subsets = [[]]
        # for n in nums:
        #     tmp = subsets[:]
        #     for s in tmp:
        #         subsets += [s + [n]]
        # return subsets

        ## method3
        # subsets = [[]]
        # for n in nums:
        #     for i in range(len(subsets)):
        #         subsets += [subsets[i] + [n]]
         # return subsets


    


