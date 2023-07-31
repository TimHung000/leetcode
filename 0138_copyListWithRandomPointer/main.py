from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        hashMap = {}
        # hashMap = {None : None}

        cur = head
        while cur:
            newNode = Node(cur.val)
            hashMap[cur] = newNode
            cur = cur.next
        
        cur = head
        while cur:
            newNode = hashMap[cur]
            newNode.next = hashMap.get(cur.next, None)
            newNode.random = hashMap.get(cur.random, None)
            cur = cur.next
        
        return hashMap[head]
    
class Solution1:
    def copyRandomList(self, head: 'Node') -> 'Node':
        hashMap = {}
        def deep_copy(node):
            if not node: 
                return None
            if node in hashMap: 
                return hashMap[node]
            
            newNode = Node(node.val)
            hashMap[node] = newNode
            newNode.next = deep_copy(node.next)
            newNode.random = deep_copy(node.random)
            return newNode
        return deep_copy(head)
