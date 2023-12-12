#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle) 
    {
        std::vector<int> mini = triangle[triangle.size()-1];
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < triangle[i].size(); ++j )
                mini[j] = triangle[i][j] + std::min(mini[j],mini[j+1]);
        return mini[0];
    }
};


int main() {
    std::vector<std::vector<int>> test {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution().minimumTotal(test);
}