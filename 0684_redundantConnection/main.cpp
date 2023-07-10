#include <vector>

class Solution {
private:
    int find(std::vector<int>&parent, std::vector<int>& rank, int n) {
        int p = parent[n];
        while(p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool union_find(std::vector<int>&parent, std::vector<int>& rank, int n1, int n2) {
        int p1 = find(parent, rank, n1);
        int p2 = find(parent, rank, n2);
        if(p1 == p2)
            return false;
        
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] = rank[p1] + rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] = rank[p2] + rank[p1];
        }
        return true;
    }
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        if(edges.size()==0) return{};
        
        std::vector<int> parent(edges.size() + 1);
        std::vector<int> rank(edges.size() + 1, 1);
        for(int i = 1 ; i < edges.size() + 1; ++i){
            parent[i]=i;
        }

        for(std::vector<int> edge : edges)
            if(!union_find(parent, rank, edge[0], edge[1]))
                return edge;
        
        return {};
    }
};