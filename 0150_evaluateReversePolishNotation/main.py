from typing import List
import math

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for val in tokens:
            if val in {'+', '-', '*', '/'}:
                x2 = stack.pop()
                x1 = stack.pop()
                if val == '+':
                    y = x1 + x2
                elif val == '-':
                    y = x1 - x2
                elif val == '*':
                    y = x1 * x2
                elif val == '/':
                    y = math.trunc(x1 / x2)
                else:
                    raise Exception("not support" + val + "as an operator")
                stack.append(y)
            else:
                stack.append(int(val))
        return stack.pop()
