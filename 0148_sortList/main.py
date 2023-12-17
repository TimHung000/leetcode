from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# merge sort
class Solution:

    def get_mid(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        slow = head
        fast = head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        return slow
    
    def merge(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        
        if not list2:
            return list1
        
        dummy = ListNode()
        cur = dummy
        while list1 and list2:
            if list1.val <= list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next
            cur = cur.next
        
        if list1:
            cur.next = list1
        
        if list2:
            cur.next = list2
        
        return dummy.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        m = self.get_mid(head)
        r = m.next
        m.next = None

        lList = self.sortList(head)
        rList = self.sortList(r)
        res = self.merge(lList, rList)

        return res

# my solution
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        tmp = []
        cur = head
        while cur:
            tmp.append((cur.val, cur))
            cur = cur.next

        tmp.sort(key=lambda node: node[0])
        dummy = ListNode()
        cur = dummy
        for node in tmp:
            cur.next = node[1]
            cur = node[1]
        cur.next = None
        
        return dummy.next