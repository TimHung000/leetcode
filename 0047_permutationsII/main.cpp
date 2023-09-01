#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
class Solution {
private:
    void dfs(std::vector<int>& perm, std::unordered_map<int,int>& countMap, std::vector<int> nums, std::vector<std::vector<int>>& res) {
        if(perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for(auto [key, value]: countMap) {
            if(value == 0)
                continue;
            perm.push_back(key);
            --countMap[key];
            dfs(perm, countMap, nums, res);
            ++countMap[key];
            perm.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> perm;
        std::unordered_map<int, int> countMap;
        for(auto num: nums)
            ++countMap[num];
        dfs(perm, countMap, nums, res);
        return res;
    }
};

class Solution1 {
private:
    void dfs(int startIdx, std::vector<int> nums, std::vector<std::vector<int>>& res) {
        if(startIdx == nums.size()) {
            res.push_back(nums);
            return;
        }

        std::unordered_set<int> mySet;
        for(int i = startIdx; i < nums.size(); ++i) {
            if(mySet.find(nums[i]) != mySet.end())
                continue;
            mySet.insert(nums[i]);
            std::swap(nums[startIdx], nums[i]);
            dfs(startIdx + 1, nums, res);
            std::swap(nums[startIdx], nums[i]);
        }
    }
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
};