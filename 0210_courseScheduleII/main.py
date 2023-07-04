from typing import List
import collections

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        preq = {i:set() for i in range(numCourses)}
		# Create a graph for adjacency and traversing.
        graph = collections.defaultdict(set)
        for i,j in prerequisites:
            preq[i].add(j)
            graph[j].add(i)
        
        myQueue = collections.deque([])
        for k, v in preq.items():
            if len(v) == 0:
                myQueue.append(k)
        
        res = []
        while myQueue:
            course = myQueue.popleft()
            res.append(course)
            if len(res) == numCourses:
                return res
            for next in graph[course]:
                preq[next].remove(course)
                if not preq[next]:
                    myQueue.append(next)
        return []
    
    def findOrder1(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = collections.defaultdict(list)
        visited = set()
        recursion_visited = []
        res = []
        for i,j in prerequisites:
            graph[j].append(i)

        def dfs(i):
            visited.add(i)
            recursion_visited.append(i)
            for j in graph[i]:
                if j not in visited:
                    dfs(j)
                elif j in recursion_visited:
                    return
            res.append(i)
            recursion_visited.pop()    

        for i in range(numCourses):
            if i not in visited:
                dfs(i)
                
        return reversed(res) if len(res) == numCourses else []
    
