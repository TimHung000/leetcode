#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;

        sort(intervals.begin(), intervals.end());
        int res = 0;
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] < prevEnd) {
                // we remove the interval end last becasue this will delete less interval
                prevEnd = min(intervals[i][1], prevEnd);
                ++res;
            }
            else
                prevEnd = intervals[i][1];
        }
        return res;
    }
};