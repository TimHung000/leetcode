from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total = 0
        surplus = 0
        res = 0
        for i in range(len(gas)):
            total += (gas[i] - cost[i])
            surplus += (gas[i] - cost[i])
            if surplus < 0:
                surplus = 0
                res = i + 1

        if total < 0:
            res = -1
        return res