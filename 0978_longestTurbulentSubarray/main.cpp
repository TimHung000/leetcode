#include <vector>
#include <algorithm>
class Solution {
public:
    int maxTurbulenceSize(std::vector<int>& arr) {
        int inc = 1;
        int dec = 1;
        int res = 1;
        for(int i = 1; i < arr.size(); ++i) {
            if(arr[i] > arr[i-1]) {
                inc = dec + 1;
                dec = 1;
            } else if(arr[i] < arr[i-1]) {
                dec = inc + 1;
                inc = 1;
            } else {
                inc = dec = 1;
            }
            res = std::max(res, std::max(dec, inc));
        }
        return res;
    }
};