from functools import cmp_to_key
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=cmp_to_key(lambda lhs, rhs: (lhs[0]-lhs[1]) - (rhs[0]-rhs[1])))
        res = 0
        n = len(costs) // 2
        for i, cost in enumerate(costs):
            if i < n:
                res += cost[0]
            else:
                res += cost[1]
        return res
