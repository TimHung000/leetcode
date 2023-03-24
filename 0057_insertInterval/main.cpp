#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int ptr = 0;
        // find the first place to add newInterval
        while(ptr < intervals.size() && intervals[ptr][1] < newInterval[0])
        {
            res.push_back(intervals[ptr]);
            ++ptr;
        }
        // find the added interval
        while(ptr < intervals.size() && intervals[ptr][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[ptr][0], newInterval[0]);
            newInterval[1] = max(intervals[ptr][1], newInterval[1]);
            ++ptr;
        }

        res.push_back(newInterval);
        while(ptr < intervals.size())
        {
            res.push_back(intervals[ptr]);
            ++ptr;
        }
        return res;
    }
};