#include <bits/stdc++.h>

using namespace std;

// bruteforce recursion
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return helper(nums, target, 0);
    }
private:
    int helper(vector<int>& nums, int target, int current) {
        if(target == current)
            return 1;
        if(target < current)
            return 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            res = res + helper(nums, target, current + nums[i]);
        }
        return res;
    }
};

class Solution1 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(nums, target, 0, dp);
    }
private:
    int helper(vector<int>& nums, int target, int current, vector<int>& dp) {
        if(target == current)
            return 1;
        if(target < current)
            return 0;
        if(dp[current] != -1)
            return dp[current];
        
        int res = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            res = res + helper(nums, target, current+nums[i], dp);
        }
        dp[current] = res;
        return res;
    }
};

class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i) {
            for(int j = 0; j < nums.size(); ++j)
            {
                if(i >= nums[j])
                    dp[i] = dp[i] + dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};