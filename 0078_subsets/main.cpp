#include <vector>


class Solution {
private:
    void dfs(std::vector<int>& nums, int index, std::vector<int>& subset, std::vector<std::vector<int>>& res) {
        if(index >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(nums, index+1, subset, res);

        subset.pop_back();
        dfs(nums, index+1, subset, res);
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }

};

class Solution1 {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res = {{}};
        for (int num : nums) {
            int n = res.size();
            for (int i = 0; i < n; i++) {
                res.push_back(res[i]); 
                res.back().push_back(num);
            }
        }
        return res;
    }
}; 