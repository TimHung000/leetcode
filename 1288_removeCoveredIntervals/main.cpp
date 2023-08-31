#include <vector>
#include <algorithm>

class Solution {
public:
    static bool cmp(std::vector<int>& lhs, std::vector<int>& rhs) {
        if(lhs[0] != rhs[0])
            return lhs[0] < rhs[0];
        else
            return lhs[1] > rhs[1];
    }
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), cmp);
        int res = intervals.size();
        int prevR = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][1] <= prevR)
                --res;
            else
                prevR = intervals[i][1];
        }
        return res;
    }
};