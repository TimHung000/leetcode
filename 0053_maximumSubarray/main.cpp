#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        // dp[i] is the lenth of subarray that must contain ith number
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max = dp[0];

        for(int i = 1; i < nums.size(); ++i) {
            if(dp[i-1] > 0) {
                dp[i] = dp[i-1] + nums[i];
            } else
                dp[i] = nums[i];

            if(dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};