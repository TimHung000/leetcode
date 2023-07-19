#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int sum;
        while(l < r) {
            sum = numbers[l] + numbers[r];
            if(sum == target)
                break;
            else if(sum > target)
                --r;
            else
                ++l;
        }
        return {l+1, r+1};
    }
};