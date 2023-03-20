#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>


using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> frequencyMap;
        for(int i = 0; i < nums.size(); ++i)
            frequencyMap[nums[i]]++;

        auto cmp = [&](const pair<int,int>& lhs, const pair<int,int>& rhs) { return lhs.second < rhs.second;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for(auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it)
        {
            pq.push(*it);
        }

        while(!pq.empty() && k > 0)
        {
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }

        return res;
    }
};