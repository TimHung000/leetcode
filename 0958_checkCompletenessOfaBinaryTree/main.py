from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        q = deque([root])
        while q[0] is not None:
            node = q.popleft()
            q.append(node.left)
            q.append(node.right)

        while q and q[0] is None:
            q.popleft()

        return len(q) == 0
    
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        q = deque([root])
        prev = root
        while q:
            node = q.popleft()
            if node:
                if not prev:
                    return False
                q.append(node.left)
                q.append(node.right)
            prev = node
        return True

# first thought
class Solution2:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        q = deque([root])

        isPrevLevelLeaf = False
        while q:
            levelCount = len(q)
            encounterNull = False
            for _ in range(levelCount):
                node = q.popleft()
                if not node.left:
                    encounterNull = True
                else:
                    if isPrevLevelLeaf:
                        return False
                    elif encounterNull:
                        return False
                    else:
                        q.append(node.left)

                if not node.right:
                    encounterNull = True
                else:
                    if isPrevLevelLeaf:
                        return False
                    elif encounterNull:
                        return False
                    else:
                        q.append(node.right)

            if len(q) != levelCount * 2:
                isPrevLevelLeaf = True

        return True

root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3, TreeNode(6)))
Solution().isCompleteTree(root)