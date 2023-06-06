#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
        std::set<int> res; 
        for(int i = 0; i < triplets.size(); ++i) {
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
                continue;
            
            for(int j = 0; j < target.size(); ++j) {
                if(triplets[i][j] == target[j])
                    res.insert(j);
            }
        }
        return res.size() == 3;
    }
};