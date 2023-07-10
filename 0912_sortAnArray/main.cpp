#include <vector>
#include <algorithm>
#include <cstdlib> // rand()
class Solution {
private:
    int partition(std::vector<int> &nums, int i, int j){
        int pivotIndex = i;
        int end = j;
        i++;
        
        while(i<=j){
            while(i<=end && nums[i] < nums[pivotIndex]){
                i++;
            }
            while(j >= pivotIndex && nums[j] > nums[pivotIndex]){
                j--;
            }
            if(i<=j){
                std::swap(nums[i++], nums[j--]);
            }
        }
        std::swap(nums[pivotIndex], nums[j]);
        return j;
        
    }
    void quickSort(std::vector<int> &nums, int l, int r){
        if(l<r){
			//swapping element at index l with element at random index
            std::swap(nums[l + rand() % (r -l + 1)], nums[l]);
            int mid = partition(nums, l, r);
            quickSort(nums, l, mid-1);
            quickSort(nums, mid+1, r);
        }
    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};