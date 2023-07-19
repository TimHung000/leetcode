class Solution:
    def validPalindrome(self, s: str) -> bool:
        def verify(l, r, deleted):
            while l < r:
                if s[l] != s[r]:
                    if deleted == 0:
                        return False
                    else:
                        return verify(l+1, r, deleted-1) or verify(l, r-1, deleted-1)
                l += 1
                r -= 1
            return True
        
        return verify(0, len(s)-1, 1)
    
    def validPalindrome1(self, s):
        i = 0
        while i < len(s) / 2 and s[i] == s[-(i + 1)]: 
            i += 1
            
        s = s[i:len(s) - i]
        return s[1:] == s[1:][::-1] or s[:-1] == s[:-1][::-1]
