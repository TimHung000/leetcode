import collections
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        res = ""
        countT = collections.defaultdict(int)
        
        for c in t:
            countT[c] += 1

        matchT = 0
        lPtr = rPtr = 0
        while rPtr < len(s):
            countT[s[rPtr]] -= 1
            if countT[s[rPtr]] >= 0:
                matchT += 1
            
            while matchT == len(t):
                if res == "" or rPtr - lPtr + 1 < len(res):
                    res = s[lPtr: rPtr + 1]

                countT[s[lPtr]] += 1
                if countT[s[lPtr]] > 0:
                    matchT -= 1
                lPtr += 1
            rPtr += 1

        return res
    
class Solution1:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        
        countT, window = {}, {}
        
        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        have, need = 0, len(countT)
        res, resLen = [-1, -1], float("inf")
        l = 0
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)

            if c in countT and window[c] == countT[c]:
                have += 1

            while have == need:
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = r - l + 1

                window[s[l]] -= 1
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1

        l, r = res
        return s[l:r + 1] if resLen != float('inf') else ""