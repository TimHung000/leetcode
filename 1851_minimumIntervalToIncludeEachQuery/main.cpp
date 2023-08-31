#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_map>
#include <set>

class Solution {
public:
    std::vector<int> minInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<int> queriesSorted = queries;
        std::sort(queriesSorted.begin(), queriesSorted.end());
        std::unordered_map<int, int> resMap;
        // minHeap
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        int i = 0;
        int l, r;
        for(int query: queriesSorted) {
            while(i < intervals.size()) {
                l = intervals[i][0];
                r = intervals[i][1];
                if(l > query)
                    break;
                pq.push({r - l + 1, r});
                ++i;
            }

            while(!pq.empty() && pq.top().second < query)
                pq.pop();

            if(!pq.empty())
                resMap[query] = pq.top().first;
            else
                resMap[query] = -1;
        }

        std::vector<int> res;
        for(auto query: queries)
            res.push_back(resMap[query]);
        return res;
    }
};

class Solution1 {
public:
    std::vector<int> minInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& queries) {
		std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &lhs, const std::vector<int> &rhs){
			return lhs[1] - lhs[0] < rhs[1] - rhs[0];
		});

		std::set<std::pair<int, int>> mySet;
		for(int i = 0; i < queries.size(); i++)
			mySet.insert({queries[i], i});

		std::vector<int> res(queries.size(), -1);
		for(auto &it : intervals){
			auto itl = mySet.lower_bound({it[0], 0});
			auto itr = mySet.upper_bound({it[1], queries.size()});
			while(itl != itr){
				int ind = itl -> second;
				res[ind] = it[1] - it[0] + 1;
				mySet.erase(itl++);
			}		 
		}

		return res;
    }
};