#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        int m, res, leftSize;
        while(l <= r) {
            m = (l + r) / 2;
            if((m - 1 < 0 || nums[m-1] != nums[m]) && (m + 1 == nums.size() || nums[m] != nums[m+1])) {
                res = nums[m];
                break;
            }

            if(m > 0 && nums[m-1] == nums[m])
                leftSize = m - 1;
            else
                leftSize = m;
            
            if(leftSize % 2 == 0)
                l = m + 1;
            else
                r = m - 1;
        }
        return res;
    }
};