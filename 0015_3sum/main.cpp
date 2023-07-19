#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int i, j, k, sum;
        for(i = 0; i < nums.size()-2; ++i) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            j = i + 1;
            k = nums.size() - 1;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum > 0)
                    --k;
                else if(sum < 0)
                    ++j;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while(nums[j] == nums[j-1] && j < k)
                        ++j;
                }
            }
        }
        return res;
    }
};