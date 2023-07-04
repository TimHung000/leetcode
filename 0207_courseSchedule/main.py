from typing import List
class Solution:
    def buildAdjacencyList(self, n, edgeList):
        adjList = [[] for _ in range(n)]
        for v1, v2 in edgeList:
            adjList[v2].append(v1)
        return adjList
    
    # dfs
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = self.buildAdjacencyList(numCourses, prerequisites)
        state = [0] * numCourses # 0: not visited, 1: all descendants are processed, -1: vertex is being processed

        def isCyclic(v):
            if state[v] == 1:
                return False
            if state[v] == -1:
                return True

            state[v] = -1
            for next in adjList[v]:
                if isCyclic(next):
                    return True
            state[v] = 1
            return False

        for i in range(numCourses):
            if isCyclic(i):
                return False
        return True
    
    # dfs with stack
    def canFinish1(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = self.buildAdjacencyList(numCourses, prerequisites)
        visited = set()

        def isCyclic(v, stack):
            if v in visited:
                if v in stack:
                    return True
                return False

            visited.add(v)
            stack.append(v)

            for i in adjList[v]:
                if isCyclic(i, stack):
                    return True

            stack.pop()
            return False

        for i in range(numCourses):
            if isCyclic(i, []):
                return False
        return True
    
    # bfs with Kahn's algo for topological sorting
    def canFinish2(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        return True if self.topoBFS(numCourses, prerequisites) else False
    
    def topoBFS(self, numNodes, edgesList):
        adjList = self.buildAdjacencyList(numNodes, edgesList)

        inDegrees = [0] * numNodes
        for v1, _ in edgesList:
            inDegrees[v1] += 1

        # a queue of all vertices with no incoming edge
        queue = []
        for v in range(numNodes):
            if inDegrees[v] == 0:
                queue.append(v)

        count = 0
        topoOrder = []

        while queue:
            v = queue.pop(0) # pop index 0
            topoOrder.append(v)
            count += 1

            # for each descendant of current vertex, reduce its in-degree by 1
            for des in adjList[v]:
                inDegrees[des] -= 1
                # if in-degree becomes 0, add it to queue
                if inDegrees[des] == 0:
                    queue.append(des)

        if count != numNodes:
            return None  # graph has at least one cycle
        else:
            return topoOrder