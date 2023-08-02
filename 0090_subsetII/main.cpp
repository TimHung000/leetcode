#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& nums, std::vector<int>& subset, std::vector<std::vector<int>>& res, int startIdx) {
        if(startIdx == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[startIdx]);
        backtrack(nums, subset, res, startIdx + 1);
        subset.pop_back();

        while(startIdx + 1 < nums.size() && nums[startIdx] == nums[startIdx + 1])
            ++startIdx;
        backtrack(nums, subset, res, startIdx + 1);

    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        std::sort(nums.begin(), nums.end());
        backtrack(nums, subset, res, 0);
        return res;
    }
};