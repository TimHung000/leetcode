#include <vector>
#include <queue>

class Solution {
private:
    bool kahnAlgo(std::vector<std::vector<int>> &adj, int n, std::vector<int> &indegree, std::vector<int> &res)
    {
        std::queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto a : adj[curr])
            {
                indegree[a] -= 1;
                if (indegree[a] == 0)
                    q.push(a);
            }
            res.push_back(curr);
            count++;
        }

        if (count != n)
            return false;
        return true;
    }
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        std::vector<std::vector<int>> adj(numCourses); // Adjacency matrix.
        std::vector<int> indegree(numCourses, 0); // indegree array.

        for (int i = 0; i < n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;
        }

        std::vector<int> res;
        if (kahnAlgo(adj, numCourses, indegree, res))
            return res;

        return {};
    }
};