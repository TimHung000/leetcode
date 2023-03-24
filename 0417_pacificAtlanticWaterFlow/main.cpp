#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> toPacific(heights.size(),vector<bool>(heights[0].size(), false));
        vector<vector<bool>> toAtlantic(heights.size(),vector<bool>(heights[0].size(), false));

        for(int row = 0; row < heights.size(); ++row)
        {
            dfs(heights, toPacific, row, 0, INT_MIN);
            dfs(heights, toAtlantic, row, heights[row].size()-1, INT_MIN);
        }

        for(int col = 0; col < heights[0].size(); ++col)
        {
            dfs(heights, toPacific, 0, col, INT_MIN);
            dfs(heights, toAtlantic, heights.size()-1, col, INT_MIN);
        }

        for(int row = 0; row < heights.size(); ++row)
        {
            for(int col = 0; col < heights[row].size(); ++col)
            {
                if(toPacific[row][col] && toAtlantic[row][col])
                    res.push_back(vector<int>{row, col});
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& height, vector<vector<bool>>& isVisited, int row, int col, int prevHeight)
    {
        const int direction[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        if(row < 0 || row >= height.size() || col < 0 || col >= height[0].size() || isVisited[row][col] || prevHeight > height[row][col])
            return;
        
        isVisited[row][col] = true;
        for(int i = 0; i < 4; ++i)
        {
            dfs(height, isVisited, row + direction[i][0], col + direction[i][1], height[row][col]);
        }
    }
};