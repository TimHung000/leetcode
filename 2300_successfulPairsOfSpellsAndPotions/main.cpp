#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> res(spells.size());

        int l, r, m, idx;
        for(int i = 0; i < spells.size(); ++i) {
            l = 0;
            r = potions.size() - 1;
            while(l <= r) {
                m = (l + r) / 2;
                if((long long)spells[i] * potions[m] >= success) {
                    r = m - 1;
                } else
                    l = m + 1;
            }
            res[i] = potions.size() - l;
        }
        return res;
    }
};