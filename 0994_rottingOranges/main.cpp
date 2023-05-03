#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> rottenQueue;
        int freshCount = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1)
                    ++freshCount;
                if(grid[i][j] == 2)
                    rottenQueue.push(make_pair(i, j));
            }
        }

        vector<pair<int,int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int res = 0;
        int r, c, rr, cc, rottenQueueSize;
        while(!rottenQueue.empty() && freshCount > 0) {
            rottenQueueSize = rottenQueue.size();
            // all rotten node
            for(int i = 0; i < rottenQueueSize; ++i) {
                r = rottenQueue.front().first;
                c = rottenQueue.front().second;
                rottenQueue.pop();
                for(auto& d : direction) {
                    rr = r + d.first;
                    cc = c + d.second;

                    if(rr < 0 || cc < 0 || rr >= grid.size() || cc >= grid[0].size() || grid[rr][cc] == 0 || grid[rr][cc] == 2)
                        continue;

                    grid[rr][cc] = 2;
                    --freshCount;
                    rottenQueue.push({rr, cc});
                }
            }
            ++res;
        }

        if(freshCount > 0)
            res = -1;
        return res;

    }

};

int main() {
    vector<vector<int>> input = {{0,1}};
    Solution sol;
    sol.orangesRotting(input);

}