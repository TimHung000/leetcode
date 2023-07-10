#include <vector>
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> exist;

        for(int idx = 0; idx < nums.size(); idx++) {
            if(exist.find(nums[idx]) != exist.end())
                return true;
            else
                exist.insert(nums[idx]);
        }
        return false;
    }
};