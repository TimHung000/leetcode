from typing import Optional, List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        queue: deque[Optional[TreeNode]] = deque()
        queue.append(root)
        res = []
        while queue:
            size = len(queue)
            for i in range(size):
                curNode = queue.popleft()
                if curNode.left:
                    queue.append(curNode.left)
                if curNode.right:
                    queue.append(curNode.right)
                if i == size - 1:
                    res.append(curNode.val)
        return res


        