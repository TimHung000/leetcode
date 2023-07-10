#include <vector>
#include <queue>
#include <iostream>

class Solution {
private:
    std::vector<std::vector<int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool inValid(std::vector<std::vector<int>>& grid, int row, int col) {
        return row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size();
    }

    void dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, std::queue<std::pair<int,int>>&q, int row, int col){
        if(inValid(grid, row, col) || visited[row][col] || grid[row][col] == 0) 
            return;
        visited[row][col] = true;
        q.push({row, col});
        for(int i = 0; i < direct.size(); ++i)
            dfs(grid, visited, q, row + direct[i][0], col + direct[i][1]);
    }
public:
    int shortestBridge(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int,int>> q;
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

        bool explored = false;
        for(int i = 0; i < grid.size() && !explored; ++i){
            for(int j = 0; j < grid[0].size() && !explored; ++j){
                if(grid[i][j]) {
                    dfs(grid, visited, q, i, j); 
                    explored = true;
                }
            }
        }

        int res = 0;
        while(!q.empty()){
            int curLen = q.size();
            for(int i = 0; i < curLen; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int j = 0; j < direct.size(); ++j) {
                    int cur_row = row + direct[j][0];
                    int cur_col = col + direct[j][1];
                    if(inValid(grid, cur_row, cur_col) || visited[cur_row][cur_col])
                        continue;
                    if(grid[cur_row][cur_col] == 1)
                        return res;
                    q.push({cur_row, cur_col});
                    visited[cur_row][cur_col] = true;
                }
            }
            ++res;
        }
        return -1;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};
    Solution sol = Solution();
    int i = sol.shortestBridge(grid);
    std::cout << i <<std::endl;
    return 0;
}