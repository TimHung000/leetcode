#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        int res = 0;
        while(l <= r) {
            if(people[l] + people[r] <= limit) {
                ++l;
            }
            --r;
            ++res;
        }

        return res;        
    }
};