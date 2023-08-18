class ListNode:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

# doubly linked list
class BrowserHistory:
    def __init__(self, homepage: str):
        self.cur = ListNode(homepage)

    def visit(self, url: str) -> None:
        self.cur.next = ListNode(url, self.cur)
        self.cur = self.cur.next

    def back(self, steps: int) -> str:
        while self.cur.prev and steps > 0:
            self.cur = self.cur.prev
            steps -= 1
        return self.cur.val

    def forward(self, steps: int) -> str:
        while self.cur.next and steps > 0:
            self.cur = self.cur.next
            steps -= 1
        return self.cur.val
    
# stack
class BrowserHistory:
    def __init__(self, homepage: str):
        self.curIdx = 0
        self.len = 1
        self.history = [homepage]

    def visit(self, url: str) -> None:
        if self.curIdx + 1 >= len(self.history):
            self.history.append(url)
        else:
            self.history[self.curIdx + 1] = url
        
        self.curIdx += 1
        self.len = self.curIdx + 1
    
    def back(self, steps: int) -> str:
        self.curIdx = max(self.curIdx - steps, 0)
        return self.history[self.curIdx]
    
    def forward(self, steps: int) -> str:
        self.curIdx = min(self.curIdx + steps, self.len - 1)
        return self.history[self.curIdx]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)