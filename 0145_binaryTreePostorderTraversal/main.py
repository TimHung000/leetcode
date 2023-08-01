from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def postorder(node):
            if not node:
                return
            postorder(node.left)
            postorder(node.right)
            res.append(node.val)

        postorder(root)
        
        return res
    
class Solution1:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = []
        last = None
        while root or stack:
            if root:
                stack.append(root)
                root = root.left
            else:
                node = stack[-1]
                if node.right and node.right != last:
                    root = root.right
                else:
                    res.append(node.val)
                    last = node
                    stack.pop()
        return res
    
class Solution2:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        stack1 = []
        stack2 = []
        res = []
        stack1.append(root)
        while stack1:
            root = stack1.pop()
            if root.left:
                stack1.append(root.left)
            if root.right:
                stack1.append(root.right)

            stack2.append(root)
        
        while stack2:
            res.append(stack2[-1].val)
            stack2.pop()

        return res
    
