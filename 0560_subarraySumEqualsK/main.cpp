#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> prefixSum;
        int curSum = 0;
        int res = 0;
        prefixSum[curSum] = 1;
        for(auto it:nums){
            curSum += it;
            int diff = curSum - k;
            if(prefixSum.find(diff) != prefixSum.end()){
                res += prefixSum[diff];
            }
            ++prefixSum[curSum];
        }
        return res;        
    }
};