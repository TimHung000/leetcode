#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) 
    {
        std::sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size()-1; i+=2)
        {
            std::swap(nums[i],nums[i+1]);
        }
        return nums;
    }
};

class Solution1 {
public:
   std::vector<int> rearrangeArray(std::vector<int>& nums) 
   {
       for(int i=1;i<nums.size()-1;i++)
       {
           if((nums[i+1] > nums[i] && nums[i-1] < nums[i]) || (nums[i+1] < nums[i] && nums[i] < nums[i-1]))
           {
               std::swap(nums[i],nums[i+1]);
           }
       }
       return nums;
   }
};