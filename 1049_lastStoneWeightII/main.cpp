#include <vector>
#include <climits>
#include <cstdlib>

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++)
            sum += stones[i];

        int target = sum / 2;
        std::vector<std::vector<bool>> dp(stones.size() + 1, std::vector<bool>(target + 1, false));
     
        for (int i = 0; i <= stones.size(); ++i)
            dp[i][0] = true;
     
        for (int i = 1; i <= stones.size(); ++i) {
            for (int j = 1; j <= target; ++j) {
                if (stones[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - stones[i - 1]] || dp[i- 1][j];
                else
                     dp[i][j] = dp[i - 1][j];
             }
        }
      
        for (int j = target; j >= 0; --j) {
            if (dp[dp.size()-1][j] == true)
                return std::abs(j - (sum - j));
        }
        
        return 0; 
    }
};


int main() {
    std::vector<int> test {2,7,4,1,8,1};
    Solution().lastStoneWeightII(test);
}