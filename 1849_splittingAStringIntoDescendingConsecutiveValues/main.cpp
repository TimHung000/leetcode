#include <string>

class Solution {
private:
    bool backtrack(int startIdx, unsigned long long prev, std::string& s) {
        if(startIdx == s.size())
            return true;
        std::string curString = "";
        unsigned long long curVal;
        for(int endIdx = startIdx; endIdx < s.size(); ++endIdx) {
            curString.push_back(s[endIdx]);
            curVal = std::stoull(curString);
            if(curVal + 1 == prev && backtrack(endIdx+1, curVal, s))
                return true;
        }
        return false;
    }
public:
    bool splitString(std::string s) {
        std::string curString = "";
        unsigned long long curVal;
        // at most s.substr(0, s.size()-1)
        for(int i = 0; i < s.size()-1; ++i) {
            curString.push_back(s[i]);
            curVal = std::stoull(curString);
            if(backtrack(i+1, curVal, s))
                return true;
        }
        return false;
    }
};