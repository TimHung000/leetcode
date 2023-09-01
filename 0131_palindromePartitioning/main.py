from typing import List

class Solution:
    def isPalindrome(self, s, l, r):
        while l < r:
            if s[l] != s[r]:
                return False
            l, r = l + 1, r - 1
        return True
    
    def partition(self, s: str) -> List[List[str]]:
        res = []
        part = []

        def dfs(startIdx):
            if startIdx == len(s):
                res.append(part.copy())
                return
            for i in range(startIdx, len(s)):
                if self.isPalindrome(s, startIdx, i):
                    part.append(s[startIdx:i+1])
                    dfs(i + 1)
                    part.pop()
                
        dfs(0)
        return res
    
class Solution1(object):
    def partition(self, s):
        if not s: 
            return [[]]
        res = []
        for i in range(1, len(s) + 1):
            if s[:i] == s[:i][::-1]:  # prefix is a palindrome
                for suf in self.partition(s[i:]):  # process suffix recursively
                    res.append([s[:i]] + suf)
        return res