#include <string>
#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> radiant;
        std::queue<int> dire;

        int len = senate.size();
        for(int i = 0; i < len; ++i) {
            if(senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        int radiantFront, direFront; 
        while(!radiant.empty() && !dire.empty()) {
            radiantFront = radiant.front();
            direFront = dire.front();
            radiant.pop();
            dire.pop();
            if(radiantFront < direFront)
                radiant.push(radiantFront + len);
            else
                dire.push(direFront + len);
        }

        return !radiant.empty() ? "Radiant" : "Dire";
    }
};