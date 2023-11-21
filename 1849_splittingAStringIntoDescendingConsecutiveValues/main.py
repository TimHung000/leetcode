class Solution:
    def splitString(self, s: str) -> bool:
        partition = []
        def backtrack(startIdx):
            if startIdx == len(s) and len(partition) >= 2:
                return True
            
            for endIdx in range(startIdx, len(s)):
                curValue = int(s[startIdx:endIdx+1])
                if len(partition) == 0 or partition[-1] == curValue + 1:
                    partition.append(curValue)
                    if backtrack(endIdx+1):
                        return True
                    partition.pop()
            return False
        
        return backtrack(0)
    

class Solution1:
    def splitString(self, s: str) -> bool:
        def backtrack(startIdx, prev):
            if startIdx == len(s):
                return True
            
            for endIdx in range(startIdx, len(s)):
                val = int(s[startIdx: endIdx+1])
                if val + 1 == prev and backtrack(endIdx+1, val):
                    return True
            return False
        
        for i in range(len(s)-1):
            val = int(s[:i+1])
            if backtrack(i+1, val):
                return True
        return False

print(Solution().splitString('050043'))
