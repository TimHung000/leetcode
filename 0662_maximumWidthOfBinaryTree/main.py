from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        res = 1
        q = deque([(root, 1)])
        while q:
            levelCount = len(q)
            res = max(res, q[-1][1] - q[0][1] + 1)
            for _ in range(levelCount):
                node, ithNode = q.popleft()
                if node.left:
                    q.append((node.left, ithNode * 2 - 1))
                if node.right:
                    q.append((node.right, ithNode * 2))
        return res