from typing import List

class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        if len(arr) < 2:
            return len(arr)

        cur_length = 1
        max_length = 1
        cur_direction = 0
        for i in range(1, len(arr)):
            tmp_direction = arr[i] - arr[i-1]
            direction_change = tmp_direction * cur_direction
            if direction_change > 0:
                cur_length = 2
            elif direction_change < 0:
                cur_length += 1
            elif tmp_direction == 0:
                cur_length = 1
            elif cur_direction == 0:
                cur_length += 1

            cur_direction = tmp_direction
            max_length = max(max_length, cur_length)
        return max_length
    
    def maxTurbulenceSize1(self, arr: List[int]) -> int:
        inc, dec, res = 1, 1, 1
        for i in range(1, len(arr)):
            if(arr[i] > arr[i-1]):
                inc = dec + 1
                dec = 1
            elif(arr[i] < arr[i-1]):
                dec = inc + 1
                inc = 1
            else:
                inc = 1
                dec = 1
            res = max(res, max(dec, inc))
        return res