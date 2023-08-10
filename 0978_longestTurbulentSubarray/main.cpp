#include <vector>
#include <algorithm>
class Solution {
public:
    int maxTurbulenceSize(std::vector<int>& arr) {
        int l = 0;
        int r = 1;
        int res = 1;
        char prev = ' ';
        while(r < arr.size()) {
            if(arr[r-1] > arr[r] && prev != '>') {
                res = std::max(res, r-l+1);
                ++r;
                prev = '>';
            } else if(arr[r-1] < arr[r] && prev != '<') {
                res = std::max(res, r-l+1);
                ++r;
                prev = '<';
            } else {
                if(arr[r] == arr[r-1])
                    ++r;
                l = r - 1;
                prev = ' ';                    
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> arr {9, 9};
    Solution().maxTurbulenceSize(arr);
    return 0;
}