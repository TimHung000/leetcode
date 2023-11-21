from typing import List

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        strSet = {s for s in nums}

        def backtrack(i, cur):
            if i == len(nums):
                s = "".join(cur)
                return None if s in strSet else s
            
            s = backtrack(i + 1, cur)
            if s:
                return s
            cur[i] = "1"
            s = backtrack(i + 1, cur)
            if s:
                return s
        
        return backtrack(0, ["0" for c in nums])
    
class Solution1:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        strSet = {s for s in nums}

        def backtrack(curStr):
            if len(curStr) == len(nums) and curStr not in strSet:
                return curStr
            
            if len(curStr) < len(nums):
                res = backtrack(curStr + '0')
                if res:
                    return res
                res = backtrack(curStr + '1')
                if res:
                    return res

        
        return backtrack("")