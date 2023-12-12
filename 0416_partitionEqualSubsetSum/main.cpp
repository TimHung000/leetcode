#include <vector>
#include <unordered_set>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
            total += nums[i];

        if (total % 2 != 0)
            return false;


        int target = total / 2;
        std::unordered_set<int> possible;
        possible.insert({0});
        
        for (int i = 0; i < nums.size(); i++) {
            std::unordered_set<int> newPossible({nums[i]});
            for (auto it = possible.begin(); it != possible.end(); it++)
                newPossible.insert(*it + nums[i]);
        
            possible.insert(newPossible.begin(), newPossible.end());
        }
        
        return possible.find(target) != possible.end();
    }
};