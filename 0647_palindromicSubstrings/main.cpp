#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // dp
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(), false));
        int res = 0;
        // length = 1
        for(int i = 0; i < s.size(); ++i)
        {
            dp[i][i] = true;
            ++res;
        }

        // length = 2
        for(int i = 0; i < s.size()-1; ++i)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = true;
                ++res;
            }
        }
        // length >= 3
        for(int k = 3; k <= s.size(); ++k)
        {
            for(int i = 0; i <= s.size()-k; ++i)
            {
                if(s[i] == s[i+k-1] && dp[i+1][i+k-2])
                {
                    dp[i][i+k-1] = true;
                    ++res;
                }
            }
        }
        return res;
    }

    // left right pointer
    int countSubstrings1(string s)
    {
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            res += countPalindrome(s, i, i);
            res += countPalindrome(s, i, i+1);
        }
        return res;
    }

    int countPalindrome(string s, int left, int right)
    {
        int res = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            ++res;
            --left;
            ++right;
        }
        return res;
    }
};