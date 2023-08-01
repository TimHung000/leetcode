#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include <tuple> 

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> countMap;
        for(int i = 0; i < tasks.size(); ++i) {
            if (countMap.find(tasks[i]) == countMap.end()) 
                countMap[tasks[i]] = 1;
            else
                ++countMap[tasks[i]];
        }

        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
        for(auto it = countMap.begin(); it != countMap.end(); ++it) {
            maxHeap.push(it->second);
        }

        std::queue<std::tuple<int, int>> queue; 
        int time = 0;
        while(!maxHeap.empty() || !queue.empty()) {
            if(!maxHeap.empty()) {
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if(count != 0)
                    queue.push({count, time + n});
            }

            if(!queue.empty()) {
                if(std::get<1>(queue.front()) == time) {
                    maxHeap.push(std::get<0>(queue.front()));
                    queue.pop();
                }
            }
            ++time;
        }
        return time;
    }
};