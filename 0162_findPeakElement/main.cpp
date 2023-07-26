#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = -1;
        int m;
        while(l <= r) {
            m = (l + r) / 2;
            // left neighbor greater
            if(m > 0 && nums[m] < nums[m-1])
                r = m -1;
            else if(m < nums.size()-1 && nums[m] < nums[m+1])
                l = m + 1;
            else {
                res = m;
                break;
            }
        }
        return res;
        
    }
};