#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
class Solution {
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        if(points.size() <= 2)
            return points.size();

        int res = 0;
        for(int i = 0; i < points.size(); ++i) {
            std::unordered_map<double, int> countMap;
            for(int j = i + 1; j < points.size(); ++j) {
                double dy = points[i][1] - points[j][1];
                double dx = points[i][0] - points[j][0];
                double slope;
                if(dx == 0)
                    slope = std::numeric_limits<double>::max();
                else
                    slope = dy / dx;
                ++countMap[slope];
                res = std::max(res, countMap[slope] + 1);
            }
        }
        return res;
    }
};