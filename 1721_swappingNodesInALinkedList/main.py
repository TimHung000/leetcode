from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        cur = head
        for i in range(k-1):
            cur = cur.next

        l = cur
        r = head
        while cur.next:
            cur = cur.next
            r = r.next

        l.val, r.val = r.val, l.val
        return head



