#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int ROW = obstacleGrid.size();
        int COL = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(ROW, std::vector<int>(COL, 0));

        if(obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        
        for(int r = 0; r < ROW; ++r) {
            for(int c = 0; c < COL; ++c) {
                if(obstacleGrid[r][c] == 1)
                    continue;
                if(r > 0)
                    dp[r][c] = dp[r][c] + dp[r-1][c];
                if(c > 0)
                    dp[r][c] = dp[r][c] + dp[r][c-1];
            }
        }
        return dp[ROW-1][COL-1];
    }
};