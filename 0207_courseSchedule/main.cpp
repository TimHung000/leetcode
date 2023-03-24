#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<bool> isVisited(numCourses, false);
        vector<bool> recursionVisited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!isVisited[i] && isCylic(graph, isVisited, recursionVisited, i)) {
                return false;
            }
        }
        return true;
    }
private:
    
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return graph;
    }
    
    bool isCylic(vector<vector<int>>& graph, vector<bool>& isVisited, vector<bool>& recursionVisited, int nodeIdx) {
        if (isVisited[nodeIdx])
            return false;

        isVisited[nodeIdx] = true;
        recursionVisited[nodeIdx] = true;
        for (int i = 0; i < graph[nodeIdx].size(); ++i) {
            if (recursionVisited[graph[nodeIdx][i]] || isCylic(graph, isVisited, recursionVisited, graph[nodeIdx][i])) 
                return true;
        }
        recursionVisited[nodeIdx] = false;

        return false;
    }
};

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{0,1}};
    Solution sol;
    sol.canFinish(numCourses, prerequisites);
    return 0;
}