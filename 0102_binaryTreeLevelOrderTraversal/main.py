from typing import Optional, List
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        queue:collections.deque[Optional[TreeNode]] = collections.deque()
        queue.append(root)
        res = []
        while queue:
            level = []
            for i in range(len(queue)):
                curNode = queue.popleft()
                level.append(curNode.val)
                if curNode.left:
                    queue.append(curNode.left)
                if curNode.right:
                    queue.append(curNode.right)
            res.append(level)

        return res
