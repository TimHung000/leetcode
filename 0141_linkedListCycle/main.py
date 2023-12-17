from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True

        return False

class Solution1:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited = set()
        cur = head
        while cur:
            if cur in visited:
                return True
            visited.add(cur)
            cur = cur.next

        return False
        