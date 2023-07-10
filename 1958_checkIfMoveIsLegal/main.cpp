#include <vector>

class Solution {
public:
    bool checkMove(std::vector<std::vector<char>>& board, int rMove, int cMove, char color) {
        int ROWS=board.size();
        int COLS=board[0].size();
        
        std::vector<std::vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}; 
        
        char opposition = color=='W' ? 'B' : 'W'; //opposite color 
        
        for(int i = 0; i < 8; ++i) {
            int row = rMove + dirs[i][0];
            int col = cMove + dirs[i][1];
            int count = 1;
            
            while(row < ROWS && col < COLS && row >= 0 && col >= 0 && board[row][col] != '.'){
                count++;
                if(count >= 3 && board[row][col] == color) 
                    return true;
                
                if(board[row][col] != opposition) 
                    break;
                
                row += dirs[i][0];
                col += dirs[i][1];
            }
        }
        return false;
    }
};