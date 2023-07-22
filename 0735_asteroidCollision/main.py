from typing import List

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for val in asteroids:
            destroy = False
            while stack and val < 0 and stack[-1] > 0 and destroy == False:
                if val + stack[-1] < 0:
                    stack.pop()
                elif val + stack[-1] > 0:
                    destroy = True
                else:
                    destroy = True
                    stack.pop()
            if not destroy:
                stack.append(val)
        return stack

                