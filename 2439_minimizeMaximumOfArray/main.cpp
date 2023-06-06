#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minimizeArrayValue(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        long res = nums[0];
        long total = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            total = total + nums[i];
            res = std::max(res, (long)std::ceil((double)total / (i+1)));
        }
        return res;
    }
};