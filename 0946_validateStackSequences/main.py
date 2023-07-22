from typing import List

class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        i = 0
        for val in pushed:
            stack.append(val)
            while i < len(popped) and stack and popped[i] == stack[-1]:
                stack.pop()
                i += 1
        return not stack