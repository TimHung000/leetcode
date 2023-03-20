#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> column;
        set<int> row;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(set<int>::iterator columnIt = column.begin(); columnIt != column.end(); ++columnIt)
        {
            for(int rowIdx = 0; rowIdx < matrix.size(); ++rowIdx)
                matrix[rowIdx][*columnIt] = 0;
        }
        for(set<int>::iterator rowIt = row.begin(); rowIt != row.end(); ++rowIt)
        {
            for(int columnIdx = 0; columnIdx < matrix[*rowIt].size(); ++columnIdx)
                matrix[*rowIt][columnIdx] = 0;
        }
    }

    // to improve space complexity, we can record the 0 in the first row and column. Beside that, we also have to record if 0 is on the first row or column, 
    // to do that we just add two variable.
};