class Solution:
    # O(26n)
    def characterReplacement(self, s: str, k: int) -> int: 
        count = {}
        res = 0
        
        l = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)

            while (r-l+1) - max(count.values()) > k:
                count[s[l]] -= 1
                l += 1
            res = max(res, r-l+1)
        return res
    
    # O(n)
    def characterReplacement1(self, s: str, k: int) -> int:
        count = {}
        res = 0
        maxFreq = 0
        l = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            # we don't need to update maxFreq in time, cause we focus on "longest" substring which is "maxFreq +k"
            # If we can't surpass historic maxFreq, then we won't be able to generate a longer valid substring.
            maxFreq = max(maxFreq, count[s[r]])
            while (r-l+1) - maxFreq > k:
                count[s[l]] -= 1
                l += 1
            res = max(res, r-l+1)
        return res
