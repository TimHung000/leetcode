#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        int lastPtr = nums.size()-1;
        dp[lastPtr] = true;
        for(int i = lastPtr - 1; i >= 0; --i) {
            for(int step = 1; step <= nums[i] && i + step <= lastPtr; ++step) {
                if(dp[i+step] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
    
};

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int canReach = 0;
        for(int i = 0; i <= canReach; ++i)
        {
            canReach = max(canReach, i + nums[i]);
            if(canReach >= nums.size()-1)
                return true;
        }
        return false;
    }
    
};