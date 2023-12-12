from typing import List
import bisect

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = 1
        dp = [1] * len(nums)

        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
                    res = max(res, dp[i])
        
        return res
    
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        myList = [nums[0]]

        for i in range(1, len(nums)):
            if nums[i] > myList[-1]:
                myList.append(nums[i])
            else:
                idx = bisect.bisect_left(myList, nums[i])
                myList[idx] = nums[i]
        
        return len(myList)
            

    
if __name__ == "__main__":
    Solution().lengthOfLIS([10,9,2,5,3,7,101,18])