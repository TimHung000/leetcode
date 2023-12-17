from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = False

class Trie:
    def __init__(self, words: List[str]):
        self.root = TrieNode()
        for w in words:
            curr = self.root
            for c in w:
                if c not in curr.children:
                    curr.children[c] = TrieNode()
                curr = curr.children[c]
            curr.word = True


class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        trie = Trie(dictionary)
        dp = {len(s): 0}

        def dfs(i):
            if i in dp:
                return dp[i]
            
            res = 1 + dfs(i + 1) # skip curr char
            curr = trie.root
            for j in range(i, len(s)):
                if s[j] not in curr.children:
                    break
                curr = curr.children[s[j]]
                if curr.word:
                    res = min(res, dfs(j + 1))
            dp[i] = res
            return res
        return dfs(0)

class Solution2:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        words = set(dictionary)
        dp = {len(s): 0}
        def dfs(i):
            if i in dp:
                return dp[i]
            
            res = 1 + dfs(i + 1) # skip curr char
            for j in range(i, len(s)):
                if s[i:j+1] in words:
                    res = min(res, dfs(j + 1))
            dp[i] = res
            return res
        
        return dfs(0)

# time limit exceeded
class Solution3:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        words = set(dictionary)

        def dfs(i):
            if i == len(s):
                return 0
            
            res = 1 + dfs(i + 1) # skip curr char
            for j in range(i, len(s)):
                if s[i:j+1] in words:
                    res = min(res, dfs(j + 1))

            return res
        
        return dfs(0)

