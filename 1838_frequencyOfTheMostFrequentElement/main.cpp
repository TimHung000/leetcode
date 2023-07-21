#include <vector>
#include <algorithm>

class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int l = 0;
        int r = 0;
        int res = 0;
        long long total = 0;
        while(r < nums.size()) {
            total = total + nums[r];
            while(nums[r] * (r - l + 1) > total + k) {
                total = total - nums[l];
                ++l;
            }
            res = std::max(res, r - l + 1);
            ++r;
        }
        return res;
    }
};