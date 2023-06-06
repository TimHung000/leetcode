#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        std::vector<int> minuteToFail;
        for(int i = 0; i < dist.size(); ++i)
            minuteToFail.push_back((int)std::ceil((double)dist[i] / speed[i]));
        std::sort(minuteToFail.begin(), minuteToFail.end());
        int res = 0;
        for(int i = 0; i < minuteToFail.size(); ++i) {
            if(minuteToFail[i] > res)
                ++res;
            else
                break;
        }
        return res;
    }
};

int main() {
    std::vector<int> test_dist = {1, 3, 4};
    std::vector<int> test_speed = {1, 1, 1};
    Solution sol;
    sol.eliminateMaximum(test_dist, test_dist);
    return 0;
}