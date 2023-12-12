#include <vector>
#include <algorithm>

class Solution {
public:
    // dp O(n^2)
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    // greedy + binary search
    int lengthOfLIS(std::vector<int>& nums) {
        // record the array length but not exactly the number in it
        std::vector<int> sub;

        for(int i = 0; i < nums.size(); ++i) {
            if(sub.empty() || sub[sub.size()-1] < nums[i])
                sub.push_back(nums[i]);
            else {
                // when the number smaller than the last element in sub, we find the smallest element in sub that bigger than nums[i] and replace it with nums[i]
                // by this method, the length of sub array won't change. Next time we find the element that are smaller that the last element we can still find the smallest element in sub
                // and replace it.
                std::vector<int>::iterator it = lower_bound(sub.begin(), sub.end(), nums[i]);
                *it = nums[i];
            }
        }
        return sub.size();
    }
};