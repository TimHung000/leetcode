#include <vector>

class Solution {
private:
    void dfs(int n, int k, int startIdx, std::vector<int>& comb, std::vector<std::vector<int>>& res) {
        if(comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for(int i = startIdx; i <= n; ++i) {
            comb.push_back(i);
            dfs(n, k, i + 1, comb, res);
            comb.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        dfs(n, k, 1, subset, res);
        return res;
    }
};