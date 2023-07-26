#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0;
        int r = rows * cols - 1;

        int m, row, col, val;
        while(l <= r) {
            m = (l + r) / 2;
            row = m / cols;
            col = m % cols;
            val = matrix[row][col];
            if(val == target)
                return true;
            else if(val > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
};