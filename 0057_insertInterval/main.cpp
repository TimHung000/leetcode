#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> res;
        int ptr = 0;
        // find the first place to add newInterval
        while(ptr < intervals.size() && intervals[ptr][1] < newInterval[0]) {
            res.push_back(intervals[ptr]);
            ++ptr;
        }
        // find the added interval
        while(ptr < intervals.size() && intervals[ptr][0] <= newInterval[1]) {
            newInterval[0] = std::min(intervals[ptr][0], newInterval[0]);
            newInterval[1] = std::max(intervals[ptr][1], newInterval[1]);
            ++ptr;
        }

        res.push_back(newInterval);
        while(ptr < intervals.size()) {
            res.push_back(intervals[ptr]);
            ++ptr;
        }
        return res;
    }
};

class Solution1 {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector< std::vector<int> > result;

        const int START=0, END=1;
        int s=newInterval[START], e=newInterval[END];
        std::vector< std::vector<int> > left, right;
        
        for( auto& curInterval : intervals ) {
            
            if (curInterval[END] < s)
                left.push_back( curInterval );
            else if( curInterval[START] > e )
                right.push_back( curInterval );
            else {
                s = std::min(s, curInterval[START] );
                e = std::max(e, curInterval[END] );
            }
        }
        
        result.insert( result.end(), left.begin(), left.end() );
        result.push_back( {s, e} );
        result.insert( result.end(), right.begin(), right.end() );
        
        return result;
    }
};