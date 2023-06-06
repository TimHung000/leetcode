#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> res;
        std::unordered_map<char, int> lastIdx;

        for(int i=0; i < s.size(); ++i)
            lastIdx[s[i]] = i;

        int currentStart = 0;
        int currentEnd = 0;
        for(int i=0; i < s.size(); ++i) {
            currentEnd = std::max(currentEnd, lastIdx[s[i]]);
            if(i == currentEnd) {
                res.push_back(currentEnd-currentStart+1);
                currentStart = currentEnd + 1;
            }
        }
        return res;
    }
};