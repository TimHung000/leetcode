from typing import List
class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False

    def addWord(self, word):
        cur = self
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.isWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for word in words:
            root.addWord(word)

        ROW, COL = len(board), len(board[0])
        res = []
        visited = set()

        def dfs(row, col, node, word):
            if row < 0 or col < 0 or row == ROW or col == COL or \
                (row, col) in visited or board[row][col] not in node.children:
                return
            visited.add((row, col))
            node = node.children[board[row][col]]
            word += board[row][col]
            if node.isWord:
                res.append(word)

            dfs(row - 1, col, node, word)
            dfs(row + 1, col, node, word)
            dfs(row, col - 1, node, word)
            dfs(row, col + 1, node, word)

            visited.remove((row, col))

        for row in range(ROW):
            for col in range(COL):
                dfs(row, col, root, "")

        return res

