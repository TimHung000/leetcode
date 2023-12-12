#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> dp(s.size()+1, false);
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        dp[0] = true;

        for(int i = 1; i <= s.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end() ) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};