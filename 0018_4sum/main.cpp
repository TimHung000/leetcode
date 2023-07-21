#include <vector>
#include <algorithm>

class Solution {
private:
    void kSum(std::vector<std::vector<int>>& res,std::vector<int>& nums, std::vector<int>& quad, int k, int start, long long target) {
        if(nums.size() < k)
            return;
        if(k != 2) {
            for(int i = start; i < nums.size()-k+1; ++i) {
                if(i > start && nums[i] == nums[i-1])
                    continue;
                
                quad.push_back(nums[i]);
                kSum(res, nums, quad, k-1, i+1, target-nums[i]);
                quad.pop_back();
            }
            return;
        }

        int l = start;
        int r = nums.size()-1;
        long long sum;
        while(l < r) {
            sum = nums[l] + nums[r];
            if(sum < target)
                ++l;
            else if(sum > target)
                --r;
            else {
                quad.push_back(nums[l]);
                quad.push_back(nums[r]);
                res.push_back(quad);
                quad.pop_back();
                quad.pop_back();
                ++l;
                while(l < r && nums[l] == nums[l-1])
                    ++l;
            }
        }
        return;
    }
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> quad;
        std::sort(nums.begin(), nums.end());
        kSum(res, nums, quad, 4, 0, target);
        return res;
    }
};

int main(int argc, char** argv) {
    std::vector<int> test({1000000000,1000000000,1000000000,1000000000});
    Solution sol;
    sol.fourSum(test, -294967296);
}
