#include <vector>
#include <algorithm>
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        int m;
        long long hours;
        while(l <= r) {
            m = (l + r) / 2;
            hours = 0;
            for(int p: piles)
                hours = hours + (p - 1) / m + 1;
            
            if(hours <= h)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};