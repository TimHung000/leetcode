#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int leastBricks(std::vector<std::vector<int>>& wall) {
        std::unordered_map<int,int> map;
        int n = wall.size();
        for(int i = 0; i < n; ++i){
            int sum=0;
            for(int j = 0; j < wall[i].size()-1; ++j){
                sum += wall[i][j];
                ++map[sum];
            }
        }

        int maxCount=0;
        for(auto m: map){
            if(m.second > maxCount)
                maxCount = m.second;
        }
        return n - maxCount;
    }
};