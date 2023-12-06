#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int res = nums[0];
        for(int i = 1;i < nums.size();i++) {
            if(nums[i] < 0)
                std::swap(curMax, curMin);
            
            curMax = std::max(nums[i], curMax * nums[i]);
            curMin = std::min(nums[i], curMin * nums[i]);
            res = std::max(res, curMax);
        }
        return res;
    }
};

class Solution1 {
public:
    int maxProduct(std::vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
                
            int tmp = curMax * n;
            curMax = std::max(std::max(n * curMax, n * curMin), n);
            curMin = std::min(std::min(tmp, n * curMin), n);
            res = std::max(res, curMax);
        }
        
        return res;
    }
};