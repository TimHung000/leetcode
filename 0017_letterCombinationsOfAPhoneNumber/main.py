from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        digitToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "qprs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(startIdx, curStr):
            if len(curStr) == len(digits):
                res.append(curStr)
                return 
            
            for c in digitToChar[digits[startIdx]]:
                backtrack(startIdx+1, curStr + c)

        if digits:
            backtrack(0, "")

        return res