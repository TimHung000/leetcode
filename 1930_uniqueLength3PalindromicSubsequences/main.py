from typing import List
import collections
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res = set()
        left = set()
        right = collections.Counter(s)

        for i in range(len(s)):
            right[s[i]] -= 1
            if right[s[i]] == 0:
                right.pop(s[i])
            
            for j in range(26):
                c = chr(ord('a') + j)
                if c in left and c in right:
                    res.add((s[i], c))
            
            left.add(s[i])
        
        return len(res)
    
class Solution(object):
    def countPalindromicSubsequence(self, s):
        d=collections.defaultdict(list)
        for i,c in enumerate(s):
            d[c].append(i)
        ans=0
        for el in d:
            if len(d[el])<2:
                continue
            a=d[el][0]
            b=d[el][-1]
            ans+=len(set(s[a+1:b]))
        return(ans)

