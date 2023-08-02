#include <vector>

class Solution {
private:
    void dfs(std::vector<std::vector<int>>& res, std::vector<int>& subset, 
            std::vector<int>& candidates, int startIdx, int target) {
        if(startIdx >= candidates.size() || target < 0)
            return;
        if(target == 0) {
            res.push_back(subset);
            return;
        }

        subset.push_back(candidates[startIdx]);
        dfs(res, subset, candidates, startIdx, target - candidates[startIdx]);

        subset.pop_back();
        dfs(res, subset, candidates, startIdx + 1, target);
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        dfs(res, subset, candidates, 0, target);
        return res;
    }
};