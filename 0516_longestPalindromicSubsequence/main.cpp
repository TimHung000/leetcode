#include <string>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>

class Solution {
public:
    // Bottom-up approach
    // TC: O(N*N), SC: O(N*N)
    int longestPalindromeSubseq(std::string& s) {
        if(s.empty())
            return 0;
        
        const int N = s.size();
        std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));
        
        for(int i = 0; i < N; i++)
            dp[i][i] = 1;
        
        for(int l = 1; l < N; l++) {
            for(int i = 0; i < N - l; i++) {
                int j = i + l;
                
                // if there are only two chars
                if((j - i + 1) == 2) {
                    // individually they are palindromic so max length 1
                    dp[i][j] = 1 + (s[i] == s[j]);
                }
                else {
                    // for s[i:j]:
                    // longest palindrome length in s[i+1 : j-1] and +1 if s[i] == s[j]
                    // if s[i] != s[j], longest length palindrome = Max of longest palin in s[i:j-1] and s[i+1:j]
                    if(s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][N-1];
    }
    

};

class Solution1 {
public:
    // Using memoization
    // TC: O(N*N), SC: O(N*N)
    int longestPalindSubseqRec(std::vector<std::vector<int> >& dp, std::string& s, int i, int j) {
        if(i > j)
            return 0;

        if(i == j)
            return dp[i][j] = 1;
        
        if(dp[i][j] == -1) {
            if(s[i] == s[j])
                dp[i][j] = 2 + longestPalindSubseqRec(dp, s, i+1, j-1);
            else
                dp[i][j] = std::max(longestPalindSubseqRec(dp, s, i+1, j),
                               longestPalindSubseqRec(dp, s, i, j-1));
        }
        return dp[i][j];
    }
    
    int longestPalindromeSubseq(std::string& s) {
        if(s.empty())
            return 0;

        const int N = s.size();
        // dp(i, j): length of longest palindromic substring in s[i:j]
        std::vector<std::vector<int> > dp(N, std::vector<int>(N, -1)); 
        
        return longestPalindSubseqRec(dp, s, 0, N-1);
    }
};