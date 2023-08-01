#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for(int i = 0; i < nums.size(); ++i) {
            minHeap.push(nums[i]);
            if (i >= k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};

class Solution1 {
public:
    int findKthLargest1(std::vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        int pivot = findPivotPos(nums, start, end);
        while(pivot != k-1) {
            if(pivot > k-1)
                end = pivot - 1;
            else
                start = pivot + 1;

            pivot = findPivotPos(nums, start, end);
        }

        return nums.at(pivot);
    }

    int findPivotPos(std::vector<int>& nums, int start, int end) {
        int pivot = start;
        int pivot_value = nums.at(start);
        ++start;
        while(start <= end) {
            while(nums.at(start) >= pivot_value) {
                ++start;
                if(start > end) break;
            }
            while(nums.at(end) < pivot_value)
                --end;
            if(start < end) {
                std::swap(nums[start], nums[end]);
                ++start;
                --end;
            }
        }
        std::swap(nums[pivot], nums[end]);
        return end;

    }
};
