// #include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm> // swap
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        queue<pair<int, int>> myQueue;
        bool isSurrounded;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 'O' && isVisited[i][j] == false) {
                    isSurrounded = true;
                    dfs(board, isVisited, myQueue, isSurrounded, i, j);
                    if(isSurrounded == true) {
                        while(!myQueue.empty()) {
                            board[myQueue.front().first][myQueue.front().second] = 'X';
                            myQueue.pop();
                        }
                    } else {
                        myQueue = {};                
                    }
                }
            }
        }
    }

    void solve1(vector<vector<char>>& board) {
        //Moving over firts and last column   
        for(int i = 0; i < board.size(); ++i) {
            if(board[i][0] == 'O')
                dfs1(board, i, 0);
            if(board[i][board[0].size()-1] == 'O')
                dfs1(board, i, board[0].size()-1);
        }

        //Moving over first and last row   
        for(int j = 0; j < board[0].size(); ++j) {
            if(board[0][j] == 'O')
                dfs1(board, 0, j);
            if(board[board.size()-1][j] == 'O')
                dfs1(board, board.size()-1, j);
        }


        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& isVisited, queue<pair<int,int>>& myQueue, bool& isSurrounded, int row, int col) {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            isSurrounded = false;
            return;
        }
        
        if(board[row][col] == 'X' || isVisited[row][col] == true)
            return;
        
        myQueue.push(make_pair(row, col));
        isVisited[row][col] = true;
        dfs(board, isVisited, myQueue, isSurrounded, row-1, col);
        dfs(board, isVisited, myQueue, isSurrounded, row, col+1);
        dfs(board, isVisited, myQueue, isSurrounded, row+1, col);
        dfs(board, isVisited, myQueue, isSurrounded, row, col-1);
    }

    void dfs1(vector<vector<char>>& board, int row, int col) {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != 'O') 
            return;
        board[row][col] = '#';
        dfs1(board, row-1, col);
        dfs1(board, row+1, col);
        dfs1(board, row, col-1);
        dfs1(board, row, col+1);
    }
};