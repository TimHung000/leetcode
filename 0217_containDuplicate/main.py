from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        exist = set()
        for num in nums:
            if num in exist:
                return True
            else:
                exist.add(num)
        return False
