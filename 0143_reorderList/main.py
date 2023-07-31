from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # find middle
        slow: ListNode = head 
        fast: ListNode = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # reverse second half
        second: ListNode = slow.next
        slow.next = None
        prev: ListNode = None
        while second:
            tmp = second.next
            second.next = prev
            prev = second
            second = tmp

        # merge two halfs
        first: ListNode = head
        second: ListNode = prev
        while second:
            tmp1: ListNode = first.next
            tmp2: ListNode = second.next
            first.next = second
            second.next = tmp1
            first, second = tmp1, tmp2

class Solution1:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        arr = []
        cur, length = head, 0
        while cur:
            arr.append( cur )
            cur, length = cur.next, length + 1
        
        cur = head
        for i in range(1, length):
            if i % 2 == 0:
                cur.next = arr[i//2]
            else:
                cur.next = arr[length - i//2 - 1]
            cur = cur.next
        cur.next = None

head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, None))))
Solution1().reorderList(head)

