#include <vector>
#include <queue>
#include <cmath>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::vector<std::vector<int>> res(k);
        std::priority_queue<std::vector<int>> maxHeap;

        int dist;
        for(int i = 0; i < points.size(); ++i) {
            dist = std::pow(points[i][0], 2) + std::pow(points[i][1], 2);
            maxHeap.push({dist, points[i][0], points[i][1]});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        std::vector<int> point;
        for(int i = 0; i < k; ++i) {
            point = maxHeap.top();
            maxHeap.pop();
            res[i] = {point[1], point[2]};            
        }
        return res;
    }
};