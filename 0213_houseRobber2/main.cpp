#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(helper(nums, 0, nums.size()-1), helper(nums, 1, nums.size()));
    }
private:
    int helper(vector<int>& nums, int start, int end) {
        if(end - start == 0)
            return 0;
        if(end - start == 1)
            return nums[start];

        int first = nums[start];
        int second = max(nums[start], nums[start+1]);
        int tmp;
        for(int i = start+2; i < end; ++i)
        {
            tmp = second;
            second = max(nums[i] + first, second);
            first = tmp;
        }
        return second;
    }
};