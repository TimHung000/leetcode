#include <string>

class Solution {
public:
    int minSwaps(std::string s) {
        
        int open = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '[')
                ++open;
            else if(open > 0)
                --open;
        }
        return (open+1) / 2; 
    }
};