#include <vector>

using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int curArea = 0;
        vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(isVisited[i][j] == false) {
                    curArea = explore(isVisited, grid, i, j);
                    if(curArea > maxArea)
                        maxArea = curArea;
                }

            }
        }
        return maxArea;
    }
private:
    int explore(vector<vector<bool>>& isVisited, vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || isVisited[row][col] == true)
            return 0;
        
        isVisited[row][col] = true;
        if(grid[row][col] == 0)
            return 0;
        
        return 1 + explore(isVisited, grid, row-1, col) + explore(isVisited, grid, row, col+1) + explore(isVisited, grid, row+1, col) + explore(isVisited, grid, row, col-1);
    }
};