#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int numSubseq(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        int mod = 1e9 + 7;
        int l = 0;
        int r = nums.size() - 1;

        std::vector<int> pows(nums.size(), 1);

        for (int i = 1 ; i < nums.size(); ++i)
            pows[i] = pows[i - 1] * 2 % mod;
       
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pows[r - l]) % mod;
                ++l; 
            }
        }
        return res;
    }
};