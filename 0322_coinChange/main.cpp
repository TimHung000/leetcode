#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 0; i <= amount; ++i)
        {
            for(int j = 0; j < coins.size(); ++j)
            {
                if(coins[j] <= i && dp[i-coins[j]] != -1 && (dp[i] == -1 || dp[i] > dp[i-coins[j]] + 1))
                    dp[i] = dp[i-coins[j]] + 1;
            }
        }
        return dp[amount];
    }

    int coinChange1(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};