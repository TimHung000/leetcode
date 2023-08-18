class ListNode:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.dummyLeft = ListNode(0)
        self.dummyRight = ListNode(0)
        self.dummyLeft.next = self.dummyRight
        self.dummyRight.prev = self.dummyLeft
        

    def get(self, index: int) -> int:
        cur = self.dummyLeft.next
        while cur and index > 0:
            cur = cur.next
            index -= 1
        
        if cur and cur != self.dummyRight and index == 0:
            return cur.val
        return -1
        

    def addAtHead(self, val: int) -> None:
        node, next , prev = ListNode(val), self.dummyLeft.next, self.dummyLeft 
        prev.next = node
        next.prev = node
        node.next = next
        node.prev = prev

    def addAtTail(self, val: int) -> None:
        node, next , prev = ListNode(val), self.dummyRight, self.dummyRight .prev
        prev.next = node
        next.prev = node
        node.next = next
        node.prev = prev
        

    def addAtIndex(self, index: int, val: int) -> None:
        cur = self.dummyLeft.next
        while cur and index > 0:
            cur = cur.next
            index -= 1
        
        if cur and index == 0:
            node, next , prev = ListNode(val), cur, cur.prev
            prev.next = node
            next.prev = node
            node.next = next
            node.prev = prev
        

    def deleteAtIndex(self, index: int) -> None:
        cur = self.dummyLeft.next
        while cur and index > 0:
            cur = cur.next
            index -= 1
        
        if cur and cur != self.dummyRight and index == 0:
            next , prev = cur.next , cur.prev
            prev.next = next
            next.prev = prev
            del cur

        


# Your MyLinkedList object will be instantiated and called as such:
obj = MyLinkedList()
# param_1 = obj.addAtHead(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
obj.addAtIndex(0, 10)
# obj.deleteAtIndex(index)