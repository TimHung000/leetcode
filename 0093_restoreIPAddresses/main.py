from typing import List
    
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        if len(s) > 12:
            return res
        
        def backtrack(startIdx, dots, curIP):
            if dots == 4 and startIdx == len(s):
                res.append(curIP[:-1])
                return
            if dots > 4:
                return
                
            for i in range(startIdx, min(startIdx + 3, len(s))):
                if int(s[startIdx:i+1]) <= 255 and (s[startIdx] != '0' or startIdx == i):
                    backtrack(i+1, dots + 1, curIP + s[startIdx:i+1] + '.')

        backtrack(0, 0, "")
        return res
            