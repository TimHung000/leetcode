class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        l, r = 0, 0
        res = 0
        while r < len(s):
            if s[r] in seen:
                l = max(l, seen[s[r]]+1)
            res = max(res, r-l+1)
            seen[s[r]] = r
            r += 1
        return res