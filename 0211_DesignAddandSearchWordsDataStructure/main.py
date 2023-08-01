from typing import Dict, Optional

class Node:
    def __init__(self):
        self.children: Dict[str, Optional(Node)] = {}
        self.end: bool = False

class WordDictionary:
    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        cur = self.root
        for ch in word:
            if ch in cur.children:
                cur = cur.children[ch]
            else:
                cur.children[ch] = Node()
                cur = cur.children[ch]
        cur.end = True

    def search(self, word: str) -> bool:
        def dfs(node, index):
            if index == len(word):
                return node.end
            
            if word[index] == ".":
                for child in node.children.values():
                    if dfs(child, index+1):
                        return True
                    
            if word[index] in node.children:
                return dfs(node.children[word[index]], index+1)
            
            return False
        return dfs(self.root, 0)

# Your Trie object will be instantiated and called as such:
# Your WordDictionary object will be instantiated and called as such:
obj = WordDictionary()
obj.addWord("bad")
obj.addWord("dad")
obj.addWord("mad")
param_2 = obj.search("pad")
param_2 = obj.search("bad")
param_2 = obj.search(".ad")
param_2 = obj.search("b..")