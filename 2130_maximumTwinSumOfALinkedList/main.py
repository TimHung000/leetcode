from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow: ListNode = head
        fast: ListNode = head
        res = 0

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        tmp: ListNode = None
        prev: ListNode = None
        while slow:
            tmp = slow.next
            slow.next = prev
            prev = slow
            slow = tmp
        
        first = head
        second = prev
        while second:
            res = max(res, first.val + second.val)
            first = first.next
            second = second.next
            
        return res
