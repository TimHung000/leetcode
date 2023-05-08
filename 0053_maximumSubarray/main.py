class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0

        dp = [None] * len(nums)
        dp[0] = nums[0]
        res = dp[0]

        for idx, num in enumerate(nums[1:], 1):
            dp[idx] = nums[idx] + (dp[idx-1] if dp[idx-1] > 0 else 0)
            res = max(dp[idx], res)
        
        return res

if __name__ == "__main__":
    test = [-2,1,-3,4,-1,2,1,-5,4]
    sol = Solution()
    sol.maxSubArray(test)