#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        helper(s, 0, res);
        return res;
    }
private:
    void helper(string& s, int index, int& res)
    {
        if(index >= s.size())
        {
            ++res;
            return;
        }
        int oneDigit = s[index] - '0';
        if(oneDigit >= 1 && oneDigit <= 9 )
            helper(s, index + 1, res);
        
        if(index + 1 < s.size())
        {
            int twoDigit = (s[index] - '0') * 10 + s[index+1] - '0';
            if(twoDigit >= 10 && twoDigit <= 26)
                helper(s, index + 2, res);
        }
    }
};

class Solution1 {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')
            return 0;
        vector<int> dp(s.size(), -1);
        int res = helper(s, 0, dp);
        return res;
    }
private:
    int helper(string& s, int index, vector<int>& dp)
    {
        if(index >= s.size())
            return 1;
        if(dp[index] != -1)
            return dp[index];
        
        int res = 0;
        int oneDigit = s[index] - '0';
        if(oneDigit >= 1 && oneDigit <= 9 )
            res += helper(s, index + 1, dp);
        
        if(index + 1 < s.size())
        {
            int twoDigit = (s[index] - '0') * 10 + s[index+1] - '0';
            if(twoDigit >= 10 && twoDigit <= 26)
                res += helper(s, index + 2, dp);
        }
        dp[index] = res;
        return res;
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;
        int twoDigits;
        for(int i = 2; i <= s.size(); ++i)
        {
            if(s[i-1] >= '1' && s[i-1] <= '9')
                dp[i] = dp[i] + dp[i-1];
            twoDigits = (s[i-2] - '0') * 10 + s[i-1] - '0';
            if(twoDigits >= 10 && twoDigits <= 26)
                dp[i] = dp[i] + dp[i-2];
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution1 sol;
    sol.numDecodings("12");
    return 0;
}