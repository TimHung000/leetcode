from typing import List
import collections

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends_set = set(deadends)
        if "0000" in deadends_set:
            return -1
        
        myQueue = collections.deque(["0000"])
        step = 0
        while myQueue:
            for i in range(len(myQueue)):
                cur = myQueue.popleft()
                if cur == target:
                    return step
                for str_idx in range(4):
                    for inc in (-1, 1):
                        temp = str((int(cur[str_idx]) + inc + 10) % 10)
                        new_cur = cur[:str_idx] + temp + cur[str_idx+1:]
                        
                        if new_cur not in deadends_set:
                            deadends_set.add(new_cur)
                            myQueue.append(new_cur)
            step += 1
        return -1

test = ["0201","0101","0102","1212","2002"]
target = "0202"
sol = Solution()
sol.openLock(test, target)