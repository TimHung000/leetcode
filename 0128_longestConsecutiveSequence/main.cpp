#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mySet(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mySet.find(nums[i]-1) != mySet.end())
            {
                int end = nums[i] + 1;
                while(mySet.find(end) != mySet.end())
                    ++end;
                res = max(res, end - nums[i]);
            }
        }
        return res;
    }
};