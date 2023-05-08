#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        // same as maximum sub array ( without circular)
        int curMax = 0 ;
        int globalMax = nums[0];
        // used to remember the min sub array of non circular array
        int curMin = 0;
        int globalMin = nums[0];

        int total = 0;

        for(int i = 0; i < nums.size(); ++i) {
            curMax = std::max(curMax + nums[i], nums[i]);
            curMin = std::min(curMin + nums[i], nums[i]);
            total = total + nums[i];
            globalMax = std::max(globalMax, curMax);
            globalMin = std::min(globalMin, curMin);
        }

        // max(globalMax, total - globalMin) would be the answer but there is edge case if all element are negative
        // globalMax would be the largest negative value. globalMin and total would be the same
        // so the result would be 0, which is the correct ans
        return globalMax < 0 ? globalMax : std::max(globalMax, total - globalMin);

    }
};