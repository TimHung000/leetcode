#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        std::unordered_map<int, int> count;
        int l = 0;
        int res = 0;
        for(int r = 0; r < fruits.size(); ++r) {
            ++count[fruits[r]];
            while(count.size() > 2) {
                --count[fruits[l]];
                if(count[fruits[l]] == 0)
                    count.erase(fruits[l]);
                ++l;
            }
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};