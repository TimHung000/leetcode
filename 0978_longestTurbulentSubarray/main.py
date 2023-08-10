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

class Solution1:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        l, r = 0, 1
        res, prevSign = 1, ""
        while r < len(arr):
            if arr[r-1] > arr[r] and prevSign != ">":
                res = max(res, r - l + 1)
                r += 1
                prevSign = ">"
            elif arr[r-1] < arr[r] and prevSign != "<":
                res = max(res, r - l + 1)
                r += 1
                prevSign = "<"
            else:
                r = r + 1 if arr[r] == arr[r-1] else r
                l = r - 1
                prevSign = ""
        return res

Solution1().maxTurbulenceSize([9,4,2,10,7,8,8,1,9])

