#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string word, int currentIdx, int currentRow, int currentCol) {
        // match all char
        if(currentIdx == word.size())
            return true;

        // out of bound
        if(currentRow < 0 || currentRow >= board.size() || currentCol < 0 || currentCol >= board[currentRow].size())
            return false;

        // current char not match the board
        if(word[currentIdx] != board[currentRow][currentCol])
            return false;
        
        char temp = board[currentRow][currentCol];
        board[currentRow][currentCol] = NULL;

        bool res = helper(board, word, currentIdx+1, currentRow+1, currentCol) || helper(board, word, currentIdx+1, currentRow-1, currentCol) ||
                    helper(board, word, currentIdx+1, currentRow, currentCol+1) || helper(board, word, currentIdx+1, currentRow, currentCol-1);
        
        board[currentRow][currentCol] = temp;

        return res;
    }
};