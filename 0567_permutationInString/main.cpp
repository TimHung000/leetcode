#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if(s1.size() > s2.size())
            return false;

        std::vector<int> s1Count(26, 0);        
        std::vector<int> s2Count(26, 0);        
        for(int i = 0; i < s1.size(); ++i) {
            ++s1Count[s1[i]-'a'];
            ++s2Count[s2[i]-'a'];
        }

        int matches = 0;
        for(int i = 0; i < 26; ++i) {
            if(s1Count[i] == s2Count[i])
                ++matches;
        }
        if(matches == 26)
            return true;

        int l = 0;
        int index;
        for(int r = s1.size(); r < s2.size(); ++r, ++l) {
            index = s2[r] - 'a';
            ++s2Count[index];
            if(s1Count[index] == s2Count[index])
                ++matches;
            else if(s1Count[index] + 1 == s2Count[index])
                --matches;

            index = s2[l] - 'a';
            --s2Count[index];
            if(s1Count[index] == s2Count[index])
                ++matches;
            else if(s1Count[index] - 1 == s2Count[index])
                --matches;

            if(matches == 26)
                return true;
        }

        return false;
    }
};