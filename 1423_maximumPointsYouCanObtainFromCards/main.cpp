#include <vector>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        int leftPtr = 0;
        int rightPtr = cardPoints.size() - k;
        int total = 0;
        for(int i = rightPtr; i < cardPoints.size(); ++i)
            total = total + cardPoints[i];
        
        int res = total;
        for(int i = leftPtr, j = rightPtr; j < cardPoints.size(); ++i, ++j) {
            total = total + cardPoints[i] - cardPoints[j];
            if(total > res)
                res = total;
        }
        return res;
    }
};