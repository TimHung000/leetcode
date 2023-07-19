from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        num_set = set(nums)

        for val in num_set:
            if (val-1) not in num_set:
                end = val
                while (end+1) in num_set:
                    end += 1
                res = max(res, end-val+1)
        return res