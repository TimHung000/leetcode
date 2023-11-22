#include <vector>
#include <algorithm>
class Solution {
public:
    int trap(std::vector<int>& height) {
        int l = 0, r = height.size()-1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            
            if (height[l] < height[r]) {
                ++l;
                leftMax = std::max(leftMax, height[l]);
                res += leftMax - height[l];

            } else {
                --r;
                rightMax = std::max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;        
    }
};