#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1)
                    res = res + countPerimeter(grid, i, j);
            }
        }
        return res;
    }
private:
    int countPerimeter(vector<vector<int>>& grid, int row, int col) {
        int res = 0;
        if(row-1 < 0 || grid[row-1][col] == 0)
            ++res;
        if(row+1 >= grid.size() || grid[row+1][col] == 0)
            ++res;
        if(col-1 < 0 || grid[row][col-1] == 0)
            ++res;
        if(col+1 >= grid[row].size() || grid[row][col+1] == 0)
            ++res;

        return res;
    }
};
