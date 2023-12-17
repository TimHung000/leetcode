from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        dummy = ListNode(0, head)
        prev = dummy
        while prev.next and prev.next.next:
            slow = prev.next
            fast = slow.next

            slow.next = fast.next
            fast.next = slow
            prev.next = fast
            prev = slow

        return dummy.next

head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
Solution().swapPairs(head)