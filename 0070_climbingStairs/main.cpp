#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp with space complexity O(n)
    int climbStairs(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n; ++i)
        {
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }

    // dp with space complexity O(n)
    int climbStairs1(int n)
    {
        if(n <= 2) return n;

        int back2 = 1;
        int back1 = 2;
        int total = 0;
        for(int i = 2; i < n; ++i)
        {
            total = back2 + back1;
            back2 = back1;
            back1 = total;
        }
        return total;
    }

    int climbStaris2(int n)
    {
        if(n <= 2) return n;
        vector<int> dp(n+1, -1);

        return helper(n, dp);
    }

    int helper(int n, vector<int>& dp)
    {
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = helper(n-1, dp) + helper(n-2, dp);
        return dp[n];
    }

};