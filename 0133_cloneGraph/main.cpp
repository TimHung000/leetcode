#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        unordered_map<Node*, Node*> visited;

        return newNode(node, visited);
    }

    Node* newNode(Node* node, unordered_map<Node*, Node*>& visited)
    {
        if(visited.find(node) != visited.end())
            return visited[node];
        
        Node* cloneNode = new Node(node->val);
        visited[node]=cloneNode;

        for(int i = 0; i < node->neighbors.size(); ++i)
        {
            cloneNode->neighbors.push_back(newNode(node->neighbors[i], visited));
        }
        return cloneNode;
    }
};