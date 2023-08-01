from typing import Dict, Optional

class Node:
    def __init__(self):
        self.children: Dict[str, Optional(Node)] = {}
        self.end: bool = False

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        cur = self.root
        for ch in word:
            if ch in cur.children:
                cur = cur.children[ch]
            else:
                cur.children[ch] = Node()
                cur = cur.children[ch]
        cur.end = True

    def search(self, word: str) -> bool:
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                return False
            cur = cur.children[ch]
        res = cur.end
        return res

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for ch in prefix:
            if ch not in cur.children:
                return False
            cur = cur.children[ch]
        return True


# Your Trie object will be instantiated and called as such:
obj = Trie()
obj.insert("apple")
param_2 = obj.search("apple")
param_2 = obj.search("app")
param_3 = obj.startsWith("app")
obj.insert("app")
param_4 = obj.search("app")