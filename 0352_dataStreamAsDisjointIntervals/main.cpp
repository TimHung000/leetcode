#include <vector>
#include <map>

class SummaryRanges {
private:
    std::map<int, std::vector<int>> intervals;

public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        std::map<int, std::vector<int>>::iterator rIt = intervals.upper_bound(value); // first element that > value
        std::map<int, std::vector<int>>::iterator lIt = intervals.end();
        if(rIt != intervals.begin()) {
            lIt = rIt;
            --lIt;
        }

        if(lIt != intervals.end() && value >= (*lIt).second[0] && value <= (*lIt).second[1])
            return;
        
        int l = value;
        int r = value;
        if(lIt != intervals.end() && (*lIt).second[1] + 1 == value) {
            l = (*lIt).second[0];
            intervals.erase(lIt);
        }

        if(rIt != intervals.end() && (*rIt).second[0] - 1 == value) {
            r = (*rIt).second[1];
            intervals.erase(rIt);
        }
        intervals[l] = {l, r};
    }
    
    std::vector<std::vector<int>> getIntervals() {
        std::vector<std::vector<int>> res;
        for(const auto& [_, interval]: intervals)
            res.push_back(interval);
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */