#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int l = 0, r = 0;
        while(r < nums.size()) {
            if(nums[l] == nums[r]) {
                ++r;
            } else {
                ++l;
                nums[l] = nums[r];
            }
        }
        return l + 1;
    }

    int removeDuplicates1(std::vector<int>& nums) {
        int count = 0;
        auto it = std::unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        return nums.size();
    }

    int removeDuplicates2(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]) {
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        return nums.size();
    }
};
