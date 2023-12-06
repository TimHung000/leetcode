from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea = 0
        stack = [] # pair : (index, height)
        for curIdx, curHeight in enumerate(heights):
            start = curIdx
            while stack and stack[-1][1] > curHeight:
                prevIdx, prevHeight = stack.pop()
                maxArea = max(maxArea, prevHeight * (curIdx - prevIdx))
                start = prevIdx
            stack.append((start, curHeight))

        for idx, height in stack:
            maxArea = max(maxArea, height * (len(heights) - idx))
        return maxArea
    
Solution().largestRectangleArea([2, 3, 4, 6, 2 , 1, 5 , 4, 4, 6, 10 ,5])