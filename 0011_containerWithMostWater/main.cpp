#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // time complexity (n^2)
    int MaxArea(std::vector<int>& height){

        int res = 0;

        for(int start = 0; start < height.size(); start++) {
            for(int end = start + 1; end < height.size(); end++) {
                int curSize = (end - start) * (std::min(height[start], height[end]));
                if(curSize > res)
                    res = curSize;
            }
        }
        return res;
    }

    // time complexity (n)
    int MaxArea1(std::vector<int>& height) {
        int res =0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r) {
            res = std::max(res, (r - l) * std::min(height[l], height[r]));
            if(height[l] < height[r])
                ++l;
            else
                --r;
        }
        return res;
    }
};


int main(int argc, char** argv) {
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    std::cout << sol.MaxArea1(height) << std::endl;
    return 0;
}
