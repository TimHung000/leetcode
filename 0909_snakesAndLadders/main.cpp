#include <unordered_map>
#include <queue>


class Solution {
public:
    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        int n = board.size();
        std::vector<int> board_1d(n*n);
        int idx = 0;
        int row = n-1;
        int col = 0;
        int col_inc = 1;
        while(idx < n*n) {
            board_1d[idx++] = board[row][col];
            if(((n-1-row) & 1) == 0 && col == n-1) { // col : left -> right && last element of row
                col_inc = -1;
                --row;
            }
            else if (((n-1-row) & 1) != 0 && col == 0) { // col : left -> right && last element of row
                col_inc = 1;
                --row;
            }
            else
                col += col_inc;
        }

        std::unordered_map<int, int> umap;
        std::queue<int> myQueue;
        myQueue.push(0);
        umap[0] = 0;
        while(!myQueue.empty()) {
            int cur_idx = myQueue.front();
            myQueue.pop();
            for(int next_idx = cur_idx+1; next_idx <= cur_idx+6; ++next_idx) {
                int dest = board_1d[next_idx] > -1 ? board_1d[next_idx] - 1 : next_idx;
                if(umap.find(dest) == umap.end()) {
                    umap[dest] = umap[cur_idx] + 1;
                    if(dest == n*n-1)
                        return umap[dest];
                    myQueue.push(dest);
                }
            }
        }
        return -1;
    }
};

int main() {
    std::vector<std::vector<int>> test = {
        {1, 1, -1},
        {1, 1, 1},
        {-1, 1, 1}
    };
    Solution sol;
    sol.snakesAndLadders(test);
    return 0;
}