from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        
        l, r = 0, len(height) - 1
        leftMax, rightMax = height[l], height[r]
        res = 0

        while l < r:
            if leftMax < rightMax:
                l += 1
                leftMax = max(leftMax, height[l])
                res += leftMax - height[l]
            else:
                r -= 1
                rightMax = max(rightMax, height[r])
                res += rightMax - height[r]

        return res

class Solution1:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        maxLeft = [0] * n
        maxRight = [0] * n
        minLR = [0] * n

        maxHeight = 0
        for i in range(n):
            maxHeight = max(maxHeight, height[i])
            maxLeft[i] = maxHeight
        
        maxHeight = 0
        for i in range(n-1, -1, -1):
            maxHeight = max(maxHeight, height[i])
            maxRight[i] = maxHeight

        for i in range(n):
            minLR[i] = min(maxLeft[i], maxRight[i])

        res = 0
        for i in range(n):
            increment = minLR[i] - height[i]
            if increment > 0:
                res += increment

        return res


if __name__ == '__main__':
    Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1])
