#include <vector>
#include <queue>

class Solution {
public:
    std::vector<bool> checkIfPrerequisite(int numCourses, std::vector<std::vector<int>>& prerequisites, std::vector<std::vector<int>>& queries) {
        std::vector<bool> res;
        std::vector<std::vector<int>> graph(numCourses); 
        std::vector<int> indegree(numCourses, 0);
        std::vector<std::vector<bool>> table(numCourses, std::vector<bool>(numCourses,false));
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }

        std::queue<int> q;
        for(int i = 0;i < numCourses; ++i)
            if(indegree[i] == 0) 
                q.push(i);
        
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(auto &it: graph[cur])
            {
                table[cur][it] = true;
                for(int i = 0; i < numCourses; ++i)
                    // i is prerequisite of cur 
                    if(table[i][cur] == true) 
                        table[i][it] = true;

                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        for(int i = 0; i < queries.size(); ++i) 
            res.push_back(table[queries[i][0]][queries[i][1]]);
        
        return res;
    }
};