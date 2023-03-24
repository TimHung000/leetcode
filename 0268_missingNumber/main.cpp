#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size() * (nums.size()+1) / 2;  // add all number in nums and missingNumber
        for(int i = 0; i < nums.size(); ++i)
            sum = sum - nums[i];

        return sum;
    }


    // x ^ b ^ b = x
    int missingNumber(vector<int>& nums) {

        int res = 0;
        int i = 0;
        while(i < nums.size())
        {
            res = res ^ i ^ nums[i];
            ++i;
        }
        res = res ^ i;

        return res;
    }
};