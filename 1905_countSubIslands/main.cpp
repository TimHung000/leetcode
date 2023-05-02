#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // paint the island with different color.(color start from 2)
        int color = 2;
        for(int i = 0; i < grid1.size(); ++i) {
            for(int j = 0; j < grid1[i].size(); ++j) {
                if(colorIsland(grid1, i, j, color))
                    ++color;        
            }
        }

        int subIslandCount = 0;
        int islandColor;
        for(int i = 0; i < grid2.size(); ++i) {
            for(int j = 0; j < grid2[i].size(); ++j) {
                if(grid2[i][j] == 1) {
                    islandColor = grid1[i][j];
                    if(isSubIsland(grid1, grid2, i, j, islandColor) && islandColor != 0)
                        ++subIslandCount;
                }    
            }
        }
        return subIslandCount;
    }

    int countSubIslands1(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        for(int i = 0; i < grid2.size(); ++i) {
            for(int j = 0; j < grid2[i].size(); ++j) {
                if(grid2[i][j] == 1)
                    if(dfs(grid1, grid2, i, j))
                        ++res;
            }
        }
        return res;
    }
private:
    bool colorIsland(vector<vector<int>>& grid, int row, int col, int color) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1) 
            return false;

        grid[row][col] = color;
        colorIsland(grid, row-1, col, color);
        colorIsland(grid, row, col+1, color);
        colorIsland(grid, row+1, col, color);
        colorIsland(grid, row, col-1, color);

        return true;
    }

    bool isSubIsland(vector<vector<int>>& mainGrid, vector<vector<int>>& subGrid, int row, int col, int matchedColor) {
        if(row < 0 || row >= subGrid.size() || col < 0 || col >= subGrid[0].size() || subGrid[row][col] == 0)
            return true;
        // visited
        subGrid[row][col] = 0;

        bool currentMatch = matchedColor == mainGrid[row][col];
        bool top = isSubIsland(mainGrid, subGrid, row-1, col, matchedColor);
        bool right = isSubIsland(mainGrid, subGrid, row, col+1, matchedColor);
        bool down = isSubIsland(mainGrid, subGrid, row+1, col, matchedColor);
        bool left = isSubIsland(mainGrid, subGrid, row, col-1, matchedColor);
        return currentMatch && top && right && down && left;

    }

    bool dfs(vector<vector<int>>& mainGrid, vector<vector<int>>& subGrid, int row, int col) {
        if(row < 0 || row >= subGrid.size() || col < 0 || col >= subGrid[0].size() || subGrid[row][col] == 0)
            return true;

        subGrid[row][col] = 0;
        bool top = dfs(mainGrid, subGrid, row-1, col);
        bool right = dfs(mainGrid, subGrid, row, col+1);
        bool bottom = dfs(mainGrid, subGrid, row+1, col);
        bool left = dfs(mainGrid, subGrid, row, col-1);

        return top && right && bottom && left && mainGrid[row][col];
    }

};

int main() {
    vector<vector<int>> input1 = {{1,1,1,1,0,0},{1,1,0,1,0,0},{1,0,0,1,1,1},{1,1,1,0,0,1},{1,1,1,1,1,0},{1,0,1,0,1,0},{0,1,1,1,0,1},{1,0,0,0,1,1},{1,0,0,0,1,0},{1,1,1,1,1,0}};
    vector<vector<int>> input2 = {{1,1,1,1,0,1},{0,0,1,0,1,0},{1,1,1,1,1,1},{0,1,1,1,1,1},{1,1,1,0,1,0},{0,1,1,1,1,1},{1,1,0,1,1,1},{1,0,0,1,0,1},{1,1,1,1,1,1},{1,0,0,1,0,0}};
    Solution sol;
    int res = sol.countSubIslands1(input1, input2);
    cout << res << "\n";
    return 0;
}