#include <vector>
#include <algorithm>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::vector<int> candies(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }

        int res = 0;
        for (int candy : candies)
            res += candy;

        return res;
    }
};