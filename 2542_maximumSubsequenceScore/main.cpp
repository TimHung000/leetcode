#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

class Solution {
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int n = nums1.size();
        std::vector<std::pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i)
            pairs[i] = {nums1[i], nums2[i]};

        std::sort(pairs.begin(), pairs.end(), [](const std::pair<int,int> &lhs, const std::pair<int,int> &rhs) {
            return lhs.second > rhs.second;
        });
        long long n1Sum = 0;
        long long res = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq; //min heap
        for (auto& [n1, n2] : pairs) {
            pq.push(n1);
            n1Sum += n1;
            if (pq.size() > k) {
                n1Sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                res = std::max(res, n1Sum * n2);
        }
        return res;
    }
};