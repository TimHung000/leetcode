#include <vector>
#include <algorithm>
class Solution {
private:
    void backtrack(std::vector<int>& candidates, std::vector<std::vector<int>>& res,
                std::vector<int> subset, int startIdx, int target) {
        
        if(target < 0)
            return;
        if(target == 0) {
            res.push_back(subset);
            return;
        }

        for(int i = startIdx; i < candidates.size(); ++i) {
            if(i > startIdx && candidates[i] == candidates[i-1])
                continue;
            subset.push_back(candidates[i]);
            backtrack(candidates, res, subset, i + 1, target - candidates[i]);
            subset.pop_back();
        }

    }
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, res, subset, 0, target);
        return res;
    }
};