from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder or not postorder:
            return None
        
        pIdx = len(postorder) - 1
        iIdx = len(inorder) - 1
        st = []

        root = TreeNode(postorder[pIdx])
        st.append(root)
        pIdx -= 1

        while pIdx >= 0:
            node = TreeNode(postorder[pIdx])
            curRoot = st[-1]

            # go back up and find the node that has left tree
            while st and st[-1].val == inorder[iIdx]:
                curRoot = st.pop()
                iIdx -= 1

            # curRoot left tree
            if not st or curRoot != st[-1]:
                curRoot.left = node
            # curRoot right tree
            else:
                curRoot.right = node

            st.append(node)
            pIdx -= 1

        return root



class Solution1:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inorderIdx = {val: idx for idx, val in enumerate(inorder)}

        def helper(l, r):
            if l > r:
                return None
            
            root = TreeNode(postorder.pop())

            idx = inorderIdx[root.val]
            root.right = helper(idx + 1, r)
            root.left = helper(l, idx - 1)
            
            return root
        return helper(0, len(inorder) - 1)

class Solution2:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder:
            return None
        
        root = TreeNode(postorder.pop())

        idx = inorder.index(root.val)
        root.right = self.buildTree(inorder[idx+1:], postorder)
        root.left = self.buildTree(inorder[:idx], postorder)

        return root
    

if __name__ == "__main__":
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    Solution().buildTree([9,3,15,20,7], [9,15,7,20,3])