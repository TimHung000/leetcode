#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        std::sort(costs.begin(), costs.end(), 
        [](std::vector<int>left, std::vector<int>right) {
            return (std::abs(left[0]-left[1]) > std::abs(right[0]-right[1]));
        });

        int size = costs.size();
        int cityA = size / 2;
        int cityB = size / 2;
        int totalCost = 0;
        for(int i = 0; i < costs.size(); ++i) {
            if(cityA == 0) {
                totalCost += costs[i][1];
                --cityB;
            } else if(cityB == 0) {
                totalCost += costs[i][0];
                --cityA;                
            } else if(costs[i][0] <= costs[i][1]) {
                totalCost += costs[i][0];
                --cityA;
            } else {
                totalCost += costs[i][1];
                --cityB;
            }
        }
        return totalCost;
    }

    int twoCitySchedCost1(std::vector<std::vector<int>>& costs) {
        std::sort(costs.begin(), costs.end(), 
        [](std::vector<int>left, std::vector<int>right) {
            return (left[0]-left[1]) < (right[0]-right[1]);
        });

        int size = costs.size();
        int n = size / 2;
        int totalCost = 0;
        for(int i = 0; i < costs.size(); ++i) {
            if(i < n)
                totalCost = totalCost + costs[i][0];
            else
                totalCost = totalCost + costs[i][1];
        }
        return totalCost;
    }
};

int main() {
    std::vector<std::vector<int>> test = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
    Solution sol;
    sol.twoCitySchedCost(test);
}