#include <vector>
#include <numeric>
class Solution {
private:
    bool backtrack(int i, int curSum, int k, int& target, std::vector<int>& nums, std::vector<bool>& selected) {
        if(k == 0)
            return true;
        
        if(curSum == target)
            return backtrack(0, 0, k - 1, target, nums, selected);
        
        for(int j = i; j < nums.size(); ++j) {
            if(selected[j] || curSum + nums[j] > target)
                continue;
            
            selected[j] = true;
            if(backtrack(j + 1, curSum + nums[j], k, target, nums, selected))
                return true;
            selected[j] = false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if(nums.size() < k || total % k)
            return false;
        int target = total / k;
        std::vector<bool> selected(nums.size(), false);
        return backtrack(0, 0, k, target, nums, selected);
    }
};