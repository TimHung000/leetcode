#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int minimumDeviation(std::vector<int>& nums) {
        int res = INT_MAX, minNum = INT_MAX;
        std::priority_queue<int> pq;
        for (auto num : nums) {
            num = num % 2 ? num * 2 : num;
            pq.push(num);
            minNum = std::min(minNum, num); 
        }
        int num;
        while (pq.top() % 2 == 0) {
            num = pq.top();
            pq.pop();
            res = std::min(res, num - minNum);
            minNum = std::min(minNum, num / 2);
            pq.push(num / 2);
        }
        res = std::min(res, pq.top() - minNum);
        return res;
    }
};