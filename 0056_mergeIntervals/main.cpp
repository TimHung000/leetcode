#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            // the end of prev interval is smaller than current start, then merge them
            if(res[res.size()-1][1] >= intervals[i][0])
                res[res.size()-1][1] = std::max(res[res.size()-1][1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;

    }
};