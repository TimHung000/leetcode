#include <vector>
#include <climits>
class Solution {
public:
    long long gridGame(std::vector<std::vector<int>>& grid) {
        int N = grid[0].size();
        
        std::vector<std::vector<long long>> prefixSum(2, std::vector<long long>(N));
        prefixSum[0][0] = grid[0][0];
        prefixSum[1][0] = grid[1][0];
        
        for(int i = 1;i < N; ++i) {
            prefixSum[0][i] = prefixSum[0][i-1] + grid[0][i];
            prefixSum[1][i] = prefixSum[1][i-1] + grid[1][i];
        }
        
        long long res = std::numeric_limits<long long>::max();
        long long row1, row2;
        for(int i = 0; i < N; ++i) {
            row1 = prefixSum[0][N-1] - prefixSum[0][i];
            row2 = i > 0 ? prefixSum[1][i-1] : 0;
            res = std::min(res,std::max(row1, row2));
        }
        return res;
    }
};