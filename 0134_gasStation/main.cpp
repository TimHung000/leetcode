#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int res = 0;
        int total = 0;
        int surplus = 0;
        for(int i = 0; i < gas.size(); ++i) {
            total = total + gas[i] - cost[i];
            surplus = surplus + gas[i] - cost[i];
            if(surplus < 0) {
                surplus = 0;
                res = i + 1;
            }
        }
        if(total < 0)
            res = -1;
        return res;
    }
};