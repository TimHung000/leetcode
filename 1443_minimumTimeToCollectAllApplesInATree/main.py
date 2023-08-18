from typing import List

class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = { i: [] for i in range(n)}
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(curNode, parent):
            time = 0

            for child in adj[curNode]:
                if child == parent:
                    continue
                childTime = dfs(child, curNode)
                if childTime or hasApple[child]:
                    time += 2 + childTime
            return time
        
        return dfs(0, -1)
    
Solution().minTime(7, [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
, [False,False,True,False,True,True,False])