from typing import List


# binary search
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        l = 1
        r = len(nums) - 1
        while l < r:
            m = l + (r - l) // 2
            cnt = 0
            for i in range(len(nums)):
                if nums[i] <= m:
                    cnt += 1

            if cnt <= m:
                l = m + 1
            else:
                r = m
        return l
    

# Fast Slow Pointer
# use index as node, value is the pointer
# the duplicate will be the start of cycle, because at least 2 value will pointer to same index
# begining point to start of cycle is equal to intersection to the start of cycle
# https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = 0, 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        # in this point slow and fast intersect

        slow2 = 0
        while True:
            slow = nums[slow]
            slow2 = nums[slow2]
            if slow == slow2:
                break
        
        return slow
