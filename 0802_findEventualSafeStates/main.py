class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        safe = {}

        def dfs(idx):
            if idx in safe: 
                return safe[idx]
            
            safe[idx] = False
            for neighbor in graph[idx]:
                if not dfs(neighbor):
                    return False

            # no neighbor
            safe[idx] = True
            return True
                
        return [idx for idx in range(n) if dfs(idx)]