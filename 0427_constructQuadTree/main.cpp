#include <vector>

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
private:
    Node* dfs(int n, int row, int col, std::vector<std::vector<int>>& grid) {
        bool allSame = true;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[row][col] != grid[row + i][col + j])
                    allSame = false;
            }
        }
        if(allSame)
            return new Node(grid[row][col], true);
        
        n = n / 2;
        Node* topLeft = dfs(n, row, col, grid);
        Node* topRight = dfs(n, row, col + n, grid);
        Node* bottomLeft = dfs(n, row + n, col, grid);
        Node* bottomRight = dfs(n, row + n, col + n, grid);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(std::vector<std::vector<int>>& grid) {
        return dfs(grid.size(), 0, 0, grid);
    }
};