#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int len = nums.size();
        std::vector<int> res(len, 1);

        // prefix product
        for (int i = 1; i < len; i++) 
            res[i] = res[i - 1] * nums[i - 1];

        // postfix product
        int postfix = nums[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};