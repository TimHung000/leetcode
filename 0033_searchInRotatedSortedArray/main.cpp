#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l, r, m;
        l = 0;
        r = nums.size() - 1;

        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;

            // left portion sorted
            if (nums[m] >= nums[l]) {
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {  // right portion sorted
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
};