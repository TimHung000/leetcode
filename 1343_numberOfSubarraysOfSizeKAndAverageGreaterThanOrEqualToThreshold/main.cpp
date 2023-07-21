#include <vector>

class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        if(arr.size() < k)
            return -1;
        
        int res = 0;
        threshold = threshold * k;
        int total = 0;
        for(int i = 0; i < k - 1; ++i)
            total = total + arr[i];
        
        for(int r = k-1; r < arr.size(); ++r) {
            total = total + arr[r];
            if(total >= threshold)
                ++res;
            total = total - arr[r-k+1];
        }
        return res;
    }
};