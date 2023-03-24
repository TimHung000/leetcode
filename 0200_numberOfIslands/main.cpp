#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int row = 0; row < grid.size(); ++row)
        {
            for(int col = 0; col < grid[0].size(); ++col)
            {
                if(grid[row][col] == '1')
                {
                    dfs(grid, row, col);
                    ++res;
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
    }
};