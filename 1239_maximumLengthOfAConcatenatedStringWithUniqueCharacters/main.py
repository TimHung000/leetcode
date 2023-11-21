from typing import List
from collections import defaultdict, Counter

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        charSet = set()

        def overlap(charSet, s):
            counter = Counter(charSet) + Counter(s)
            return max(counter.values()) > 1
            # prev = set()
            # for c in s:
            #     if c in charSet or c in prev:
            #         return True
            #     prev.add(c)
            # return False

        def backtrack(curIdx):
            if curIdx == len(arr):
                return len(charSet)
            res = 0
            if not overlap(charSet, arr[curIdx]):
                for c in arr[curIdx]:
                    charSet.add(c)
                res = backtrack(curIdx + 1)
                for c in arr[curIdx]:
                    charSet.remove(c)
            return max(res, backtrack(curIdx + 1))

        return backtrack(0)
    
class Solution1:
    def maxLength(self, arr: List[str]) -> int:
        maxlen = 0
        def backtrack(startIdx, cur: List[str]):
            nonlocal maxlen
            curStr = ''.join(cur)
            if len(curStr) == len(set(curStr)):
                maxlen = max(maxlen, len(curStr))
            
            for i in range(startIdx, len(arr)):
                if len(curStr) > len(set(curStr)):
                    break
                cur.append(arr[i])
                backtrack(i + 1, cur)
                cur.pop()

        backtrack(0, [])
        return maxlen
    
class Solution2:
    def maxLength(self, arr: List[str]) -> int:
        maxlen = 0
        unique = ['']

        for word in arr:
            for item in unique:
                tmp = item + word
                if len(tmp) == len(set(tmp)):
                    unique.append(tmp)
                    maxlen = max(maxlen, len(tmp))

        return maxlen
    
class Solution3:
    def maxLength(self, arr: List[str]) -> int:
        dp = [set()]

        for word in arr:
            charSet = set(word)
            if len(charSet) < len(word):
                continue
            for item in dp:
                if not (charSet & item):
                    dp.append(item | charSet)

        lengthMap = map(lambda x: len(x), dp)
        return max(lengthMap)
    
print(Solution1().maxLength(["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"]))
            