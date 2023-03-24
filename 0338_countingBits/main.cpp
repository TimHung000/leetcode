#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i = 0; i <= n; ++i)
        {
            int current = i;
            int currentRes = 0;
            int currentDigit = 1;
            while(current)
            {
                currentRes = currentRes + (current % 2) * currentDigit;
                current = current / 2;
            }
            res.push_back(currentRes);
        }
        return res;
    }
};