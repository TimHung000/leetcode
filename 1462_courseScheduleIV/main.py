from typing import List
import collections

class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        adj = [set() for _ in range(numCourses)]
        indegrees = [0] * numCourses
        ancestors = [set() for _ in range(numCourses)]

        for i in range(len(prerequisites)):
            pre, next = prerequisites[i][0], prerequisites[i][1]
            adj[pre].add(next)
            indegrees[next] += 1
        
        myQueue = collections.deque()
        for a in range(len(indegrees)):
            if(indegrees[a] == 0):
                myQueue.append(a)

        while myQueue:
            curr = myQueue.pop()
            neighbors = adj[curr]
            for neighbor in neighbors:
                indegrees[neighbor] -= 1
                ancestors[neighbor].add(curr)
                ancestors[neighbor].update(ancestors[curr])
                if(indegrees[neighbor] == 0):
                    myQueue.append(neighbor)

        res = []
        for query in queries:
            all_prereqs = ancestors[query[1]]
            if(query[0] in all_prereqs):
                res.append(True)
            else:
                res.append(False)
        
        return res