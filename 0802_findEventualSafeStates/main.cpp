#include <vector>

class Solution {
private: 
    bool dfs(vector<vector<int>> &graph, int node, vector<bool> &safe, vector<bool> &visited){
        bool curr_ans = true;
        visited[node] = true;
        
        for(int j:graph[node]){
            if(!visited[j])
                curr_ans = curr_ans && dfs(graph, j, safe, visited);
            else
                curr_ans = curr_ans && safe[j];
        }
        safe[node]=curr_ans;
        return curr_ans;
    }
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
        int n = graph.size();

        std::vector<bool> visited(n, false);

        std::vector<bool> safe(n, false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(graph, i, safe, visited);
            }
        }
        std::vector<int> res;
        for(int i=0; i<n; i++){
            if(safe[i])
                res.push_back(i);
        }
        return res;
    }
};