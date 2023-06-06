#include <vector>
#include <map>
#include <queue>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize !=0)
            return false;
        
        std::map<int, int> myMap;
        for(int i = 0; i < hand.size(); ++i) {
            ++myMap[hand[i]];
        }

        while(myMap.size() != 0) {
            int cur = myMap.begin()->first;
            for(int i = 0; i < groupSize; ++i) {
                if(myMap[cur+i] == 0)
                    return false;
                else if(--myMap[cur+i] == 0)
                    myMap.erase(cur+i);
            }
        }
        return true;

    }
};