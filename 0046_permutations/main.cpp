#include <vector>
#include <algorithm>

class Solution {
private:
    void dfs(int startIdx, std::vector<int>& nums, std::vector<std::vector<int>>& res) {
        if(startIdx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i = startIdx; i < nums.size(); ++i) {
            std::swap(nums[startIdx], nums[i]);
            dfs(startIdx + 1, nums, res);
            std::swap(nums[startIdx], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
};