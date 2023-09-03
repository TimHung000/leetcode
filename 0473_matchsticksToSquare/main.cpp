#include <vector>
#include <numeric> // accumulate
#include <algorithm>
class Solution {
private:
    bool backtrack(int idx, int length, std::vector<int>& sides, std::vector<int>& matchsticks) {
        if(idx == matchsticks.size())
            return true;
        
        for(int i = 0; i < 4; ++i) {
            if(sides[i] + matchsticks[idx] <= length) {
                sides[i] = sides[i] + matchsticks[idx];
                if(backtrack(idx + 1, length, sides, matchsticks))
                    return true;
                sides[i] = sides[i] - matchsticks[idx];
            }
        }
        return false;
    }
public:
    bool makesquare(std::vector<int>& matchsticks) {
        if(matchsticks.size() < 4) 
            return false;
        
		int sum = std::accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum % 4 != 0) 
            return false;
        
		int length= sum / 4;
        std::vector<int> sides(4, 0);
		std::sort(matchsticks.rbegin(), matchsticks.rend());
        
		return backtrack(0, length, sides, matchsticks);
    }
};