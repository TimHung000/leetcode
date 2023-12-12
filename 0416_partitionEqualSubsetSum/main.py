from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        
        target = total / 2
        possible = set()
        for num in nums:
            newPossible = set([num])
            for val in possible:
                newPossible.add(val + num)

            possible = possible.union(newPossible)
        
        return target in possible

if __name__ == "__main__":
    print(Solution().canPartition([1,5,11,5]))