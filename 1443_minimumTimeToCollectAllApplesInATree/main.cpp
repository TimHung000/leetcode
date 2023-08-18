#include <vector>

class Solution {
private:
    int dfs(int curNode, int parent, std::vector<std::vector<int>>& adjList, std::vector<bool>& hasApple) {
        int time = 0;
        // int childTime;
        for(int child: adjList[curNode]) {
            if(child == parent)
                continue;
            int childTime = dfs(child, curNode, adjList, hasApple);
            if(childTime != 0 || hasApple[child])
                time = time + childTime + 2;
        }
        return time;
    }

public:
    int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple) {
        std::vector<std::vector<int>> adjList(n, std::vector<int>());
        for(std::vector<int> edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adjList, hasApple);
    }
};
