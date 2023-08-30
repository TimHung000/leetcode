#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        std::vector<std::vector<int>> dp(text1.size()+1, std::vector<int>(text2.size()+1, 0));
        for(int i = 0; i < text1.size(); ++i) {
            for(int j = 0; j < text2.size(); ++j) {
                if(text1[i] == text2[j])
                    dp[i+1][j+1] = dp[i][j] +1;
                else
                    dp[i+1][j+1] = std::max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};