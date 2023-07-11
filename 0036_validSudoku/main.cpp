#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::unordered_set<int>> rows(9);
        std::vector<std::unordered_set<int>> cols(9);
        std::vector<std::vector<std::unordered_set<int>>> block(3, std::vector<std::unordered_set<int>>(3));
        
        char curr;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                curr = board[i][j];
                if(curr == '.')
                    continue;

                if(rows[i].find(curr) != rows[i].end() || cols[j].find(curr) != cols[j].end() || 
                    block[i/3][j/3].find(curr) != block[i/3][j/3].end())
                    return false;
                rows[i].insert(curr);
                cols[j].insert(curr);
                block[i/3][j/3].insert(curr);
            }
        }
        return true;            
    }
};