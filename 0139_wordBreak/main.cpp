#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dp[0] = true;

        for(int i = 1; i <= s.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end() )
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};