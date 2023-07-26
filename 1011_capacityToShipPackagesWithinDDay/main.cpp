#include <vector>
#include <algorithm> // max_element
#include <numeric> // accumulate
class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r = std::accumulate(weights.begin(), weights.end(), 0);
        int m, dayNeeded, curr;
        while(l < r) {
            m = (l + r) / 2;
            dayNeeded = 1;
            curr = 0;
            for(int w : weights) {
                if(curr + w > m) {
                    ++dayNeeded;
                    curr = 0;
                }
                curr = curr + w;
            }
            if(dayNeeded > days)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};