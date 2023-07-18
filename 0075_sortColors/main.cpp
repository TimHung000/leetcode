#include <vector>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int leftPtr = 0;
        int rightPtr = nums.size()-1;
        int i = 0;
        while(i <= rightPtr) {
            if(nums[i] == 0) {
                std::swap(nums[leftPtr], nums[i]);
                ++leftPtr;
            } else if(nums[i] == 2) {
                std::swap(nums[rightPtr], nums[i]);
                --rightPtr;
                --i;
            }
            ++i;
        }
    }
};