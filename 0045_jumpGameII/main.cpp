#include <vector>
#include <algorithm>


class Solution {
public:
    // brute force
    int jump(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), nums.size()-1);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 1;i+j < nums.size() && j <= nums[i]; ++j) {
                if(dp[i] + 1 < dp[i+j]) {
                    dp[i+j] = dp[i] + 1;
                }
           }
        }
        return dp[nums.size()-1];
    }

    int jump1(std::vector<int>& nums) {
        int res = 0;
        int lastJumpPos = 0 ;
        int curFarthestReach = 0;
        int i = 0;
        while(lastJumpPos < nums.size()-1) {
            curFarthestReach = std::max(curFarthestReach, i + nums[i]);
            if(i == lastJumpPos) {
                ++res;
                lastJumpPos = curFarthestReach;
            }
            ++i;
        }
        return res;
    }
};